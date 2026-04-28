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

    // void rangeOr(int p, int l, int r, int x, int y, int v) {
    //     if (l >= y || r <= x) {
    //         return;
    //     }

    //     if ((info[p].sumAnd & v) == v) {
    //         return;
    //     }

    //     if (r - l == 1) {
    //         int nv = (info[p].sumAnd | v);
    //         info[p] = {nv, nv, std::max(0, nv), std::max(0, nv), std::max(0, nv)};
    //         return;
    //     }

    //     int m = (l + r) / 2;
    //     rangeOr(2 * p, l, m, x, y, v);
    //     rangeOr(2 * p + 1, m, r, x, y, v);
    //     pull(p);
    // }

    // void rangeOr(int l, int r, int v) {
    //     rangeOr(1, 0, n, l, r, v);
    // }

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

constexpr i64 inf = 1E18 + 1;

struct Info {
    i64 max = -inf;
    i64 min = inf;
};

Info operator+ (const Info &a, const Info &b) {
    Info c;
    c.max = std::max(a.max, b.max);
    c.min = std::min(a.min, b.min);
    return c;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, Q;
	std::cin >> N >> Q;

	SegmentTree<Info> tx(N + 5), ty(N + 5);
	for (int i = 0; i < N; i++) {
		i64 X, Y;
		std::cin >> X >> Y;
		i64 nx = X + Y, ny = X - Y;
		tx.modify(i, {nx, nx});
		ty.modify(i, {ny, ny});
	}

	while (Q--) {
		int op;
		std::cin >> op;

		if (op == 1) {
			int i;
			i64 X, Y;
			std::cin >> i >> X >> Y;
			i--;

			i64 nx = X + Y, ny = X - Y;
			tx.modify(i, {nx, nx});
			ty.modify(i, {ny, ny});
		} else {
			int L, R;
			i64 X, Y;
			std::cin >> L >> R >> X >> Y;
			L--, R--;
			i64 nx = X + Y, ny = X - Y;
			i64 mxx = tx.rangeQuery(L, R + 1).max, mnx = tx.rangeQuery(L, R + 1).min;
			i64 mxy = ty.rangeQuery(L, R + 1).max, mny = ty.rangeQuery(L, R + 1).min;

			std::cout << std::max({std::abs(mxx - nx), std::abs(mnx - nx), std::abs(mxy - ny), std::abs(mny - ny)}) << "\n";
		}
	}
	


	return 0;
}