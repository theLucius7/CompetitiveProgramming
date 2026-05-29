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

	int n, k;
	std::cin >> n >> k;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	std::vector<i64> s(n + 1);
	for (int i = 0; i < n; i++) {
		s[i + 1] = s[i] + a[i];
	}

	std::vector<i64> f(n + 1);
	std::vector<i64> v;
	v.push_back(f[0]);
	for (int i = 0; i < n; i++) {
		f[i + 1] = s[i + 1] - (i + 1) * k;
		v.push_back(f[i + 1]);
	}



	std::sort(v.begin(), v.end());

	for (int i = 0; i <= n; i++) {
		f[i] = std::lower_bound(v.begin(), v.end(), f[i]) - v.begin();
	}

	Fenwick<i64> t(n + 10);
	i64 ans = 0;
	for (int i = 0; i <= n; i++) {
		ans += t.sum(f[i] + 1);
		t.add(f[i], 1);
	}
	std::cout << ans << "\n";


	return 0;
}