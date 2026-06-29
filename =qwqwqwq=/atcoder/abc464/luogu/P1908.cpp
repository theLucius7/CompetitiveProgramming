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

	std::vector<int> v;
	for (int i = 0; i < n; i++) {
		v.push_back(a[i]);
	}

	std::sort(v.begin(), v.end());

	int max = 0;
	for (int i = 0; i < n; i++) {
		a[i] = std::lower_bound(v.begin(), v.end(), a[i]) - v.begin();
		max = std::max(max, a[i]);
	}

	Fenwick<int> fen(max + 3);
	i64 ans = 0;
	for (int i = 0; i < n; i++) {
		fen.add(a[i], 1);
		ans += fen.rangeSum(a[i] + 1, max + 2);
	}
	std::cout << ans << "\n";

	return 0;
}