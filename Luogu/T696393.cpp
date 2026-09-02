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

	int n, q;
	std::cin >> n >> q;
	int aA, aB, aC;
	int op0, opA, opB;
	int x0, xA, xB;
	int z0, zA, zB;
	std::vector<int> a(n + 1);
	std::cin >> a[0] >> aA >> aB >> aC;
	std::cin >> op0 >> opA >> opB;
	std::cin >> x0 >> xA >> xB;
	std::cin >> z0 >> zA >> zB;
	int total = 0;
	for (int i = 1; i <= n; i ++) {
		a[i] = (a[i - 1] * aA + aB) % aC;
		total += a[i];
	}

	std::vector<int> b(n);
	for (int i = 0; i < n; i++) {
		b[i] = a[i + 1];
	}

	Fenwick<i64> fen(n);
	for (int i = 0; i < n; i++) {
		fen.add(i, b[i]);
	}

	// for (int i = 0; i < n; i++) {
	// 	std::cout << b[i] << " \n"[i == n - 1];
	// }

	i64 ans = 0;
	for (int i = 1; i <= q; i ++) {
		int op = (op0 * opA + opB) % 9 + 1;
		int x = (x0 * xA + xB) % n + 1;
		int z = ((long long)z0 * zA + zB) % (op == 1 ? aC : total);
		op0 = op;
		x0 = x;
		z0 = z;


		x--;
		if (op == 1) {
			fen.add(x, z - b[x]);
			b[x] = z;
		} else if (op == 2) {
			if (fen.rangeSum(x, n) < z) {
				ans += -1;
				continue;
			}

			if (fen.sum(x) + z - 1 < 0) {
				ans += x + 1;
				continue;
			}

			int y = fen.select(fen.sum(x) + z - 1);
			ans += y + 1;
		} else if (op == 3) {
			if (fen.rangeSum(x, n) <= z) {
				ans += -1;
				continue;
			}

			if (fen.sum(x) + z < 0) {
				ans += x + 1;
				continue;
			}

			int y = fen.select(fen.sum(x) + z);
			ans += y + 1;
		} else if (op == 4) {
			if (b[x] > z) {
				ans += -1;
				continue;
			}

			if (fen.sum(x) + z < 0) {
				ans += x + 1;
				continue;
			}

			int y = fen.select(fen.sum(x) + z);
			ans += y;
		} else if (op == 5) {
			if (b[x] >= z) {
				ans += -1;
				continue;
			}


			if (fen.sum(x) + z - 1 < 0) {
				ans += x + 1;
				continue;
			}

			int y = fen.select(fen.sum(x) + z - 1);
			ans += y;
		} else if (op == 6) {
			if (fen.rangeSum(0, x + 1) < z) {
				ans += -1;
				continue;
			}

			if (fen.sum(x + 1) - z < 0) {
				ans += x + 1;
				continue;
			}

			int y = fen.select(fen.sum(x + 1) - z);
			ans += std::min(x + 1, y + 1);
		} else if (op == 7) {
			if (fen.rangeSum(0, x + 1) <= z) {
				ans += -1;
				continue;
			}

			if (fen.sum(x + 1) - z - 1 < 0) {
				ans += x + 1;
				continue;
			}

			int y = fen.select(fen.sum(x + 1) - z - 1);
			ans += std::min(x + 1, y + 1);
		} else if (op == 8) {
			if (b[x] > z) {
				ans += -1;
				continue;
			}

			if (fen.sum(x + 1) - z - 1 < 0) {
				ans += 1;
				continue;
			}


			int y = fen.select(fen.sum(x + 1) - z - 1);
			ans += y + 2;
		} else if (op == 9) {
			if (b[x] >= z) {
				ans += -1;
				continue;
			}

			if (fen.sum(x + 1) - z < 0) {
				ans += 1;
				continue;
			}

			int y = fen.select(fen.sum(x + 1) - z);
			ans += y + 2;
		}
		// std::cout << ans << " \n"[i == q];
	}

	std::cout << ans << "\n";


	return 0;
}