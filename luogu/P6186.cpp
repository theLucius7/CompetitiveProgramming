#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;
    
    Fenwick(int n_ = 0) {
        init(n_);
    }
    
    void init(int n_) {
        n = n_;
        a.assign(n, T{});
    }
    
    void add(int x, const T &v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] = a[i - 1] + v;
        }
    }
    
    T sum(int x) {
        T ans{};
        for (int i = x; i > 0; i -= i & -i) {
            ans = ans + a[i - 1];
        }
        return ans;
    }
    
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
    
    int select(const T &k) {
        int x = 0;
        T cur{};
        for (int i = 1 << std::__lg(n); i; i /= 2) {
            if (x + i <= n && cur + a[x + i - 1] <= k) {
                x += i;
                cur = cur + a[x - 1];
            }
        }
        return x;
    }
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	std::cin >> n >> m;

	std::vector<int> p(n);
	for (int i = 0; i < n; i++) {
		std::cin >> p[i];
	}

	Fenwick<int> fen(n + 5);
	std::vector<int> B(n);
	for (int i = 0; i < n; i++) {
		B[i] = fen.rangeSum(p[i] + 1, n + 3);
		fen.add(p[i], 1);
	}

	// for (int i = 0; i < n; i++) {
	// 	std::cout << b[i] << " \n"[i == n - 1];
	// }

	// return 0;

	Fenwick<i64> u(n + 5), v(n + 5);
	for (int i = 0; i < n; i++) {
		u.add(B[i], B[i]);
		v.add(B[i], 1);
	}

	while (m--) {
		int op;
		std::cin >> op;

		if (op == 1) {
			int x;
			std::cin >> x;
			x--;

			if (p[x] < p[x + 1]) {
				u.add(B[x], -B[x]);
				v.add(B[x], -1);
				u.add(B[x + 1], -B[x + 1]);
				v.add(B[x + 1], -1);
				B[x]++;
				std::swap(p[x], p[x + 1]);
				std::swap(B[x], B[x + 1]);
				u.add(B[x], B[x]);
				v.add(B[x], 1);
				u.add(B[x + 1], B[x + 1]);
				v.add(B[x + 1], 1);
			} else if (p[x] > p[x + 1]) {
				u.add(B[x], -B[x]);
				v.add(B[x], -1);
				u.add(B[x + 1], -B[x + 1]);
				v.add(B[x + 1], -1);
				B[x + 1]--;
				std::swap(p[x], p[x + 1]);
				std::swap(B[x], B[x + 1]);
				u.add(B[x], B[x]);
				v.add(B[x], 1);
				u.add(B[x + 1], B[x + 1]);
				v.add(B[x + 1], 1);
			}
			// for (int i = 0; i < n; i++) {
			// 	std::cout << p[i] << " \n"[i == n - 1];
			// }

		} else {
			int k;
			std::cin >> k;
			if (k >= n) {
				std::cout << 0 << "\n";
			} else {
				std::cout << (1LL * u.rangeSum(k + 1, n + 3) - 1LL * v.rangeSum(k + 1, n + 3) * k) << "\n";
			}
		}
	}

	return 0;
}