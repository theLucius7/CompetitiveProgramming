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
	i64 sum;
};

Info operator+(const Info &a, const Info &b) {
	return { a.sum + b.sum };
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector<i64> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	std::vector<Info> init(n);
	for (int i = 0; i < n; i++) {
		init[i].sum = a[i];
	}

	SegmentTree<Info> t(init);

	int m;
	std::cin >> m;

	while (m--) {
		int op;
		std::cin >> op;

		if (op == 0) {
			int x, y;
			std::cin >> x >> y;
			x--, y--;
			if (x > y) {
				std::swap(x, y);
			}
			for (int i = x; i <= y; i++) {
				if (a[i] == 1) {
					continue;
				}
				a[i] = std::sqrtl((long double)a[i]);
				t.modify(i, Info{a[i]});
			}
		} else {
			int x, y;
			std::cin >> x >> y;
			x--, y--;
			if (x > y) {
				std::swap(x, y);
			}
			std::cout << t.rangeQuery(x, y + 1).sum << "\n";
		}
	}

	return 0;
}