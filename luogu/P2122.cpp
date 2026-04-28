#include <bits/stdc++.h>

using i64 = long long;

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
    i64 add = 0;
    void apply(const Tag &t) & {
        add += t.add;
    }
};

struct Info {
    i64 sum = 0;
    i64 len = 0;
    i64 sum2 = 0;
    void apply(const Tag &t) & {
        sum2 += len * t.add * t.add + 2 * t.add * sum;
        sum += t.add * len;
    }
};

Info operator+(const Info &a, const Info &b) {
    return {a.sum + b.sum, a.len + b.len, a.sum2 + b.sum2};
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<Info> init(n);
    for (int i = 0; i < n; i++) {
        std::cin >> init[i].sum;
        init[i].len = 1;
        init[i].sum2 = init[i].sum * init[i].sum;
    }
    LazySegmentTree<Info, Tag> t(init);

    while (m--) {
        int op;
        std::cin >> op;

        if (op == 1) {
            int l, r;
            i64 d;
            std::cin >> l >> r >> d;
            l--, r--;
            t.rangeApply(l, r + 1, {d});
        } else if (op == 2) {
            int l, r;
            std::cin >> l >> r;
            l--, r--;
            i64 fz = t.rangeQuery(l, r + 1).sum, fm = r - l + 1;
            i64 g = std::__gcd(fz, fm);
            std::cout << fz / g << "/" << fm / g << "\n";
        } else {
            int l, r;
            std::cin >> l >> r;
            l--, r--;
            i64 fz = 1LL * (r - l + 1) * t.rangeQuery(l, r + 1).sum2 - std::powl(t.rangeQuery(l, r + 1).sum, 2), fm = 1LL * (r - l + 1) * (r - l + 1);
            i64 g = std::__gcd(fz, fm);
            std::cout << fz / g << "/" << fm / g << "\n";
        }
    }

	return 0;
}