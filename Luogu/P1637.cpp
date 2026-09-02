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

	int n;
	std::cin >> n;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	Fenwick<int> fl(1E5 + 10), fr(1E5 + 10);
	std::vector<int> cntl(n), cntr(n);
	for (int i = 0; i < n; i++) {
		cntl[i] = fl.rangeSum(0, a[i]);
		fl.add(a[i], 1);
	}
	for (int i = n - 1; i >= 0; i--) {
		cntr[i] = fr.rangeSum(a[i] + 1, 1E5 + 1);
		fr.add(a[i], 1);
	}

	i64 ans = 0;
	for (int i = 1; i < n - 1; i++) {
		ans += cntl[i] * cntr[i];
	}

	std::cout << ans << "\n";

	return 0;
}