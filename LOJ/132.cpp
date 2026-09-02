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

	std::vector<i64> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	Fenwick<i64> fen1(n), fen2(n);
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			fen1.add(i, a[i]);
			fen2.add(i, i * a[i]);
		} else {
			fen1.add(i, a[i] - a[i - 1]);
			fen2.add(i, 1LL * i * (a[i] - a[i - 1]));
		}
	}

	while (q--) {
		int op;
		std::cin >> op;

		if (op == 1) {
			int l, r, x;
			std::cin >> l >> r >> x;
			l--, r--;
			fen1.add(l, x), fen1.add(r + 1, -x);
			fen2.add(l, 1LL * l * x), fen2.add(r + 1, 1LL * (r + 1) * -x);
		} else {
			int l, r;
			std::cin >> l >> r;
			l--, r--;
			std::cout << (r + 1) * fen1.sum(r + 1) - fen2.sum(r + 1) - l * fen1.sum(l) + fen2.sum(l) << "\n";
		}
	}

	return 0;
}