#include <bits/stdc++.h>

using i64 = long long;

template<class Info>
struct SegmentTree {
    int n;
    std::vector<Info> info;
    SegmentTree() : n(0) {}
    SegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }
    template<class T>
    SegmentTree(std::vector<T> init_) {
        init(init_);
    }
    void init(int n_, Info v_ = Info()) {
        init(std::vector(n_, v_));
    }
    template<class T>
    void init(std::vector<T> init_) {
        n = init_.size();
        info.assign(4 << std::__lg(n), Info());
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
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
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

    void rangeMod(int p, int l, int r, int x, int y, i64 v) {
        if (l >= y || r <= x) {
            return;
        }

        if (info[p].max < v) {
            return;
        }

        if (r - l == 1) {
            int nv = info[p].sum % v;
            info[p] = {nv, nv};
            return;
        }

        int m = (l + r) / 2;
        rangeMod(2 * p, l, m, x, y, v);
        rangeMod(2 * p + 1, m, r, x, y, v);
        pull(p);
    }

    void rangeMod(int l, int r, i64 v) {
        rangeMod(1, 0, n, l, r, v);
    }

    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }
};

constexpr i64 inf = 1E18 + 1;

struct Info {
    i64 sum = 0;
    i64 max = 0;
};

Info operator+ (const Info &a, const Info &b) {
    return { a.sum + b.sum, std::max(a.max, b.max) };
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<Info> init(n);
    for (int i = 0; i < n; i++) {
        init[i] = {a[i], a[i]};
    }

    SegmentTree<Info> t(init);
    while (m--) {
        int op;
        std::cin >> op;

        if (op == 1) {
            int l, r;
            std::cin >> l >> r;
            l--, r--;
            std::cout << t.rangeQuery(l, r + 1).sum << "\n";
        } else if (op == 2) {
            int l, r;
            i64 x;
            std::cin >> l >> r >> x;
            l--, r--;
            t.rangeMod(l, r + 1, x);
        } else {
            int k;
            i64 x;
            std::cin >> k >> x;
            k--;
            t.modify(k, Info{x, x});
        }
    }

	return 0;
}