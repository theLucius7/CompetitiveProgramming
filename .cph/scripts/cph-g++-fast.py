#!/opt/homebrew/bin/python3 -S
"""CPH single-file GCC accelerator; unsupported invocations use GCC unchanged."""
import contextlib
import fcntl
import hashlib
import json
import os
from pathlib import Path
import re
import shlex
import shutil
import subprocess
import sys
import tempfile

GPP = Path('/opt/homebrew/bin/g++-16')
CCACHE = '/opt/homebrew/bin/ccache'
ROOT = Path(os.environ.get('CPH_CACHE_DIR', Path.home() / '.cache/cph-gcc-fast-v2'))
SOURCE = re.compile(r'.*\.(cpp|cc|cxx|CPP|cp|c\+\+|C)$')
SIMPLE = re.compile(r'-(?:std=[\w+]+|O(?:[0-3gsz]|fast)?|g(?:[0-3]|gdb[0-3]?)?|'
                    r'W(?![alp],)[\w=,+-]+|m(?:arch|cpu|tune)=[\w.+-]+|'
                    r'f(?:no-)?(?:exceptions|rtti|elide-constructors|char8_t|wrapv|'
                    r'strict-aliasing|omit-frame-pointer|signed-char|unsigned-char|'
                    r'stack-protector(?:-strong|-all)?)|'
                    r'fdiagnostics-color(?:=(?:always|never|auto))?)$')
ENV_NAMES = ('PATH', 'CPATH', 'CPLUS_INCLUDE_PATH', 'C_INCLUDE_PATH', 'SDKROOT',
             'DEVELOPER_DIR', 'MACOSX_DEPLOYMENT_TARGET', 'SOURCE_DATE_EPOCH',
             'LANG', 'LC_ALL', 'LC_CTYPE', 'LC_MESSAGES', 'TMPDIR', 'ZDOTDIR')


def digest(value):
    return hashlib.sha256(json.dumps(value, sort_keys=True).encode()).hexdigest()


def file_hash(path):
    with open(path, 'rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def stamp(path):
    try:
        st = os.stat(path)
        # stat follows symlinks; inode/dev detect retargeting without hundreds
        # of repeated realpath traversals on every cache hit.
        return [st.st_dev, st.st_ino, st.st_size, st.st_mtime_ns, st.st_ctime_ns]
    except OSError:
        return None


@contextlib.contextmanager
def locked(path):
    with open(path, 'a+b') as stream:
        fcntl.flock(stream, fcntl.LOCK_EX)
        yield


def parse(argv):
    sources, flags, output, i = [], [], None, 0
    while i < len(argv):
        arg = argv[i]
        if arg == '-o' and i + 1 < len(argv):
            i += 1
            if output is not None:
                return None
            output = argv[i]
        elif arg.startswith('-o') and len(arg) > 2:
            if output is not None:
                return None
            output = arg[2:]
        elif SOURCE.fullmatch(arg) and not arg.startswith('-'):
            sources.append(arg)
        elif arg in ('-D', '-U'):
            if i + 1 == len(argv):
                return None
            i += 1
            flags.extend((arg, argv[i]))
        elif (arg.startswith(('-D', '-U')) and len(arg) > 2 or
              arg in ('-pipe', '-pthread', '-pedantic', '-pedantic-errors', '-w',
                      '-ansi') or SIMPLE.fullmatch(arg)):
            flags.append(arg)
        else:
            return None
        i += 1
    if len(sources) != 1 or not output or output == '-':
        return None
    if Path(output).is_symlink() or (Path(output).exists() and not Path(output).is_file()):
        return None
    if '-Wsystem-headers' in flags:
        return None
    if Path(output).resolve() == Path(sources[0]).resolve():
        return None
    return sources[0], flags, Path(output).absolute()


def remove_output(output, argv):
    if output and output.is_file() and not output.is_symlink():
        sources = {Path(a).resolve() for a in argv if SOURCE.fullmatch(a)}
        if output.resolve() not in sources:
            output.unlink(missing_ok=True)


def raw(argv, output=None):
    result = subprocess.run([str(GPP), *argv])
    if result.returncode:
        remove_output(output, argv)
    return result.returncode


def toolchain():
    prefix = GPP.resolve().parent.parent
    files = [GPP, Path('/usr/bin/ld')]
    files += [Path('/Library/Developer/CommandLineTools/usr/bin') / name
              for name in ('ld', 'as', 'clang')]
    files += list(prefix.glob('libexec/gcc/*/*/cc1plus'))
    files += list(prefix.glob('libexec/gcc/*/*/collect2'))
    for name in ('libstdc++*', 'libgcc*', 'libatomic*', 'libemutls_w.a', 'libheapt_w.a'):
        files += list((prefix / 'lib/gcc').glob('*/' + name))
    files += list((prefix / 'lib/gcc/current/gcc').glob('*/*/lib*_w.a'))
    sdks = [Path('/Library/Developer/CommandLineTools/SDKs') / name
            for name in ('MacOSX.sdk', 'MacOSX26.sdk')]
    if os.environ.get('SDKROOT'):
        sdks.append(Path(os.environ['SDKROOT']))
    for sdk in sdks:
        files += [sdk, sdk / 'SDKSettings.json', sdk / 'usr/lib/libSystem.tbd']
    return sorted((str(p), stamp(p)) for p in set(files))


def ensure_pch(key, flags, env):
    variant = ROOT / 'pch' / key
    variant.mkdir(parents=True, exist_ok=True)
    with locked(variant / 'lock'):
        manifest = variant / 'current.json'
        try:
            data = json.loads(manifest.read_text())
            header = Path(data['header'])
            if (header.with_suffix('.h.gch').is_file() and
                    header.with_suffix('.h.gch.sum').is_file() and
                    all(stamp(p) == s for p, s in data['dependencies'])):
                return header.parent.parent
        except (OSError, ValueError, KeyError):
            pass
        generation = Path(tempfile.mkdtemp(prefix='generation-', dir=variant))
        header = generation / 'bits/stdc++.h'
        header.parent.mkdir()
        originals = list(GPP.resolve().parent.parent.glob('include/c++/*/*/bits/stdc++.h'))
        if len(originals) != 1:
            shutil.rmtree(generation)
            return None
        header.write_text('#include "' + str(originals[0]) + '"\n')
        pch = Path(str(header) + '.gch')
        depfile = generation / 'dependencies.d'
        # GCC cannot generate a precompiled header from stdin. Keep the complete
        # upstream header and let source-level macros decide whether its PCH fits.
        cmd = [str(GPP), *flags, '-isystem', str(generation), '-x', 'c++-header',
               str(header), '-MD', '-MF', str(depfile), '-MT', 'pch', '-o', str(pch)]
        result = subprocess.run(cmd, capture_output=True, env=env)
        if result.returncode:
            if os.environ.get('CPH_VERBOSE'):
                sys.stderr.buffer.write(result.stderr)
            shutil.rmtree(generation)
            return None  # Diagnose the user's actual source with unchanged GCC.
        words = shlex.split(depfile.read_text().replace('\\\n', ' ').split(':', 1)[1])
        dependencies = [(str(Path(p).absolute()), stamp(p)) for p in dict.fromkeys(words)]
        Path(str(pch) + '.sum').write_text(file_hash(pch) + '\n')
        temporary = variant / 'current.tmp'
        temporary.write_text(json.dumps({'header': str(header), 'dependencies': dependencies}))
        os.replace(temporary, manifest)
        return generation


def publish(source, target):
    # CPH on this Mac leaves the last .bin in place. Keep its inode when the
    # bytes still match; repeated runs do not need a new file replacement.
    if (target.is_file() and not target.is_symlink() and
            target.stat().st_mode & 0o111 and
            target.stat().st_size == source.stat().st_size and
            file_hash(target) == file_hash(source)):
        return
    fd, name = tempfile.mkstemp(prefix='.cph-fast-', dir=target.parent)
    os.close(fd)
    try:
        shutil.copy2(source, name)
        os.replace(name, target)
    finally:
        Path(name).unlink(missing_ok=True)


def replay(entry):
    sys.stdout.buffer.write((entry / 'stdout').read_bytes())
    sys.stderr.buffer.write((entry / 'stderr').read_bytes())


def self_contained(data):
    # A narrow shortcut: exactly one umbrella include, at the beginning, and
    # no hidden include/assembly dependencies. Everything else uses ccache.
    if any(token in data for token in (b'/*', b'\\\n', b'\\\r\n', b'##',
                                      b'__has_', b'_Pragma', b'asm')):
        return False
    lines = [line for line in data.splitlines() if line.strip()]
    if not lines or not re.fullmatch(rb'\s*#\s*include\s*<bits/stdc\+\+\.h>\s*(?://.*)?', lines[0]):
        return False
    directives = re.findall(rb'^\s*#\s*(\w+)', data, re.M)
    return directives.count(b'include') == 1 and all(d in (
        b'include', b'define', b'undef', b'if', b'ifdef', b'ifndef', b'else',
        b'elif', b'endif', b'error', b'warning') for d in directives)


def fast(argv, source, flags, output):
    ROOT.mkdir(parents=True, exist_ok=True)
    empty_zsh = ROOT / 'empty-zsh'
    empty_zsh.mkdir(exist_ok=True)
    env = os.environ.copy()
    env['ZDOTDIR'] = str(empty_zsh)
    environment = {name: env.get(name) for name in ENV_NAMES}
    compiler = toolchain()
    identity = [2, compiler, flags, str(Path.cwd()), environment]
    front_env = {k: environment[k] for k in ('SDKROOT', 'MACOSX_DEPLOYMENT_TARGET',
                                           'SOURCE_DATE_EPOCH', 'LANG', 'LC_ALL',
                                           'LC_CTYPE', 'LC_MESSAGES')}
    pch_dir = ensure_pch(digest([2, compiler, flags, front_env]), flags, env)
    if pch_dir is None:
        return raw(argv, output)
    binroot = ROOT / 'binaries'
    binroot.mkdir(exist_ok=True)
    data = Path(source).read_bytes()
    direct_key = digest([identity, source, str(pch_dir), hashlib.sha256(data).hexdigest(),
                         str(output)]) if self_contained(data) else None
    references = ROOT / 'direct'
    references.mkdir(exist_ok=True)
    reference = references / (direct_key + '.json') if direct_key else None
    if reference and reference.is_file() and not os.environ.get('CCACHE_DISABLE'):
        with locked(ROOT / 'binaries.lock'):
            try:
                saved = json.loads(reference.read_text())
                entry = binroot / saved['entry']
                if (entry / 'program').is_file():
                    publish(entry / 'program', output)
                    sys.stdout.buffer.write(bytes.fromhex(saved['stdout']))
                    sys.stderr.buffer.write(bytes.fromhex(saved['stderr']))
                    replay(entry)
                    os.utime(entry, None)
                    return 0
            except (OSError, ValueError, KeyError):
                pass
    env['CCACHE_SLOPPINESS'] = 'pch_defines,time_macros'
    env['CCACHE_PCH_EXTSUM'] = 'true'
    env['CCACHE_COMPILERCHECK'] = 'content'
    with tempfile.TemporaryDirectory(prefix='build-', dir=ROOT) as tmp:
        obj = Path(tmp) / 'program.o'
        dependencies = Path(tmp) / 'program.d'
        command = [CCACHE, str(GPP), *flags, '-isystem', str(pch_dir),
                   '-fpch-preprocess', '-MMD', '-MF', str(dependencies),
                   '-c', source, '-o', str(obj)]
        result = subprocess.run(command, env=env, capture_output=True)
        if result.returncode == 0:
            names = shlex.split(dependencies.read_text().replace('\\\n', ' ').split(':', 1)[1])
            if any(re.search(rb'\b__(?:DATE|TIME|TIMESTAMP)__\b', Path(p).read_bytes())
                   for p in names):
                return raw(argv, output)
        sys.stdout.buffer.write(result.stdout)
        sys.stderr.buffer.write(result.stderr)
        if result.returncode:
            remove_output(output, argv)
            return result.returncode
        compile_diagnostics = {'stdout': result.stdout.hex(), 'stderr': result.stderr.hex()}
        key = digest([identity, file_hash(obj), str(output)])
        entry = binroot / key
        with locked(ROOT / 'binaries.lock'):
            if not (entry / 'program').is_file():
                result = subprocess.run([str(GPP), str(obj), *flags, '-o', str(output)],
                                        capture_output=True, env=env)
                sys.stdout.buffer.write(result.stdout)
                sys.stderr.buffer.write(result.stderr)
                if result.returncode:
                    remove_output(output, argv)
                    return result.returncode
                staging = Path(tempfile.mkdtemp(prefix='pending-', dir=binroot))
                shutil.copy2(output, staging / 'program')
                (staging / 'stdout').write_bytes(result.stdout)
                (staging / 'stderr').write_bytes(result.stderr)
                os.replace(staging, entry)
            else:
                publish(entry / 'program', output)
                replay(entry)
            os.utime(entry, None)
            if reference and Path(source).read_bytes() == data:
                reference.write_text(json.dumps({'entry': key, **compile_diagnostics}))
                refs = sorted(references.glob('*.json'), key=lambda p: p.stat().st_mtime_ns)
                for old in refs[:-1024]:
                    old.unlink(missing_ok=True)
            entries = sorted((p for p in binroot.iterdir() if p.is_dir()),
                             key=lambda p: p.stat().st_mtime_ns, reverse=True)
            for old in entries[256:]:
                shutil.rmtree(old)
    return 0


def main():
    argv = sys.argv[1:]
    parsed = parse(argv)
    if not parsed:
        return raw(argv)
    source, flags, output = parsed
    # Custom linker/tool searches have dependencies beyond this CP-only cache.
    special_env = ('GCC_EXEC_PREFIX', 'COMPILER_PATH', 'LIBRARY_PATH', 'DEVELOPER_DIR',
                   'CPATH', 'CPLUS_INCLUDE_PATH', 'C_INCLUDE_PATH', 'OBJC_INCLUDE_PATH')
    if (any(os.environ.get(k) for k in special_env) or
            any(k.startswith(('DYLD_', 'LD_')) for k in os.environ)):
        return raw(argv, output)
    try:
        if re.search(rb'\b__(?:DATE|TIME|TIMESTAMP)__\b',
                     Path(source).read_bytes() + ' '.join(flags).encode()):
            return raw(argv, output)
        return fast(argv, source, flags, output)
    except (OSError, ValueError, KeyError) as exc:
        if os.environ.get('CPH_VERBOSE'):
            print(f'cph-fast: cache unavailable ({exc}); using GCC', file=sys.stderr)
        return raw(argv, output)


if __name__ == '__main__':
    sys.exit(main())
