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

    void rangeOr(int p, int l, int r, int x, int y, int v) {
        if (l >= y || r <= x) {
            return;
        }

        if ((info[p].sumAnd & v) == v) {
            return;
        }

        if (r - l == 1) {
            int nv = (info[p].sumAnd | v);
            info[p] = {nv, nv, std::max(0, nv), std::max(0, nv), std::max(0, nv)};
            return;
        }

        int m = (l + r) / 2;
        rangeOr(2 * p, l, m, x, y, v);
        rangeOr(2 * p + 1, m, r, x, y, v);
        pull(p);
    }

    void rangeOr(int l, int r, int v) {
        rangeOr(1, 0, n, l, r, v);
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
    int sumAnd = ~0;
    i64 maxSub = -inf;
    i64 pre = -inf;
    i64 suf = -inf;
};

Info operator+ (const Info &a, const Info &b) {
    Info c;
    c.sum = a.sum + b.sum;
    c.sumAnd = a.sumAnd & b.sumAnd;
    c.maxSub = std::max({a.suf + b.pre, a.maxSub, b.maxSub});
    c.pre = std::max(a.pre, a.sum + b.pre);
    c.suf = std::max(b.suf, a.suf + b.sum);
    return c;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	

	return 0;
}