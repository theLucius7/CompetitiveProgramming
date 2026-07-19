#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

template<class Info, class Tag>
struct LazySegmentTree {
    int n;
    std::vector<Info> info;
    std::vector<Tag> tag;
    LazySegmentTree() : n(0) {}
    LazySegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }
    template<class T>
    LazySegmentTree(std::vector<T> init_) {
        init(init_);
    }
    void init(int n_, Info v_ = Info()) {
        init(std::vector(n_, v_));
    }
    template<class T>
    void init(std::vector<T> init_) {
        n = init_.size();
        info.assign(4 << std::__lg(n), Info());
        tag.assign(4 << std::__lg(n), Tag());
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = init_[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            pull(p);
        };
        build(1, 0, n);
    }
    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    void apply(int p, const Tag &v) {
        info[p].apply(v);
        tag[p].apply(v);
    }
    void push(int p) {
        apply(2 * p, tag[p]);
        apply(2 * p + 1, tag[p]);
        tag[p] = Tag();
    }
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        push(p);
        if (x < m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }
    void modify(int p, const Info &v) {
        modify(1, 0, n, p, v);
    }
    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        push(p);
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }
    void rangeApply(int p, int l, int r, int x, int y, const Tag &v) {
        if (l >= y || r <= x) {
            return;
        }
        if (l >= x && r <= y) {
            apply(p, v);
            return;
        }
        int m = (l + r) / 2;
        push(p);
        rangeApply(2 * p, l, m, x, y, v);
        rangeApply(2 * p + 1, m, r, x, y, v);
        pull(p);
    }
    void rangeApply(int l, int r, const Tag &v) {
        return rangeApply(1, 0, n, l, r, v);
    }
    
    template<class F>
    int findFirst(int p, int l, int r, int x, int y, F &&pred) {
        if (l >= y || r <= x) {
            return -1;
        }
        if (l >= x && r <= y && !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        push(p);
        int res = findFirst(2 * p, l, m, x, y, pred);
        if (res == -1) {
            res = findFirst(2 * p + 1, m, r, x, y, pred);
        }
        return res;
    }
    template<class F>
    int findFirst(int l, int r, F &&pred) {
        return findFirst(1, 0, n, l, r, pred);
    }
    template<class F>
    int findLast(int p, int l, int r, int x, int y, F &&pred) {
        if (l >= y || r <= x) {
            return -1;
        }
        if (l >= x && r <= y && !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        push(p);
        int res = findLast(2 * p + 1, m, r, x, y, pred);
        if (res == -1) {
            res = findLast(2 * p, l, m, x, y, pred);
        }
        return res;
    }
    template<class F>
    int findLast(int l, int r, F &&pred) {
        return findLast(1, 0, n, l, r, pred);
    }
};

struct Tag {
    int x = 0;
    void apply(const Tag &t) & {
        // x = std::max(x, t.x);
    }
};

struct Info {
    int mx = -1E18, mn = 1E18;
    void apply(const Tag &t) & {
        // x = std::max(x, t.x);
    }
};

Info operator+(const Info &a, const Info &b) {
    return {std::max(a.mx, b.mx), std::min(a.mn, b.mn)};
}

void solve() {
    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    constexpr int inf = 1E18;

    auto check1 = [&](int k) {
        int len = (1 << k);

        bool ok = true;
        int lsmx = -inf, lsmn = inf;
        int mn = inf, mx = -inf;
        for (int i = 0; i <= n; i++) {
            if (i % len == 0 || i == n) {
                if (mx < lsmx || mn < lsmx) {
                    return false;
                }
                lsmx = mx;
                lsmn = mn;
                mn = inf, mx = -inf;
            }
            mn = std::min(mn, a[i]);
            mx = std::max(mx, a[i]);
        }

        if (ok) {
            return true;
        } else {
            return false;
        }
    };


    int lo = 0, hi = 30;
    while (lo < hi) {
        int m = (lo + hi) / 2;
        if (check1(m)) {
            hi = m;
        } else {
            lo = m + 1;
        }
    }
    std::cout << (1 << lo) / 2 << "\n";

    

    LazySegmentTree<Info, Tag> t(n + 10);
    for (int i = 0; i < n; i++) {
        t.modify(i, {a[i], a[i]});
    }

    auto check2 = [&](int k) {
        int len = (1 << k);

        bool ok = true;
        int lsmx = -inf, lsmn = inf;
        int mn = inf, mx = -inf;
        for (int i = 0; i < n; i += len) {
            if (mx < lsmx || mn < lsmx) {
                ok = false;
                // std::cout << i << "? ";
                break;
            }
            lsmx = mx;
            lsmn = mn;
            mn = inf, mx = -inf;


            auto res = t.rangeQuery(i, i + len);
            mx = std::max(mx, res.mx);
            mn = std::min(mn, res.mn);
        }

        if (mx < lsmx || mn < lsmx) {
            ok = false;
            // std::cout << i << "? ";
            // break;
        }
        lsmx = mx;
        lsmn = mn;
        mn = inf, mx = -inf;

        if (ok) {
            return true;
        } else{
            return false;
        }
    };

    // std::vector<std::array<int, 2>> qrys(q);
    for (int i = 0; i < q; i++) {
        // std::cin >> qrys[i][0] >> qrys[i][1];
        int id, x;
        std::cin >> id >> x;
        a[id] = x;
        t.modify(id, {a[id], a[id]});

        lo = 0, hi = 30;
        while (lo < hi) {
            int m = (lo + hi) / 2;
            if (check2(m)) {
                hi = m;
            } else {
                lo = m + 1;
            }
        }
        std::cout << (1 << lo) / 2 << "\n";


    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
