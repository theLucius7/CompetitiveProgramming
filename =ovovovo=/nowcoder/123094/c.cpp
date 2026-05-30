#include <bits/stdc++.h>

using i64 = long long;

constexpr int P = 1E8 - 3;

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

	int n;
	std::cin >> n;

	std::vector<i64> a(n), b(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		std::cin >> b[i];
	}

	std::vector<i64> v(n);
	for (int i = 0; i < n; i++) {
		v[i] = a[i];
	}
	std::sort(v.begin(), v.end());
	std::vector<int> posA(n);
	for (int i = 0; i < n; i++) {
		a[i] = std::lower_bound(v.begin(), v.end(), a[i]) - v.begin();
		posA[a[i]] = i;
	}

	for (int i = 0; i < n; i++) {
		v[i] = b[i];
	}
	std::sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		b[i] = std::lower_bound(v.begin(), v.end(), b[i]) - v.begin();
	}

	std::vector<int> c(n);
	for (int i = 0; i < n; i++) {
		c[i] = posA[b[i]];
	}

	Fenwick<int> fen(n + 1);
	i64 ans = 0;
	for (int i = 0; i < n; i++) {
		ans += fen.rangeSum(c[i] + 1, n + 1);
		ans %= P;
		fen.add(c[i], 1);
	}
	std::cout << ans % P << "\n";

	return 0;
}