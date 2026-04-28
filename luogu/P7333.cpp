#include <bits/stdc++.h>

using i64 = long long;

template<class T, class Cmp = std::less<T>>
struct RMQ {
    const int n;
    const Cmp cmp;
    std::vector<std::vector<T>> a;
    RMQ(const std::vector<T> &init) : n(init.size()), cmp(Cmp()) {
        int lg = std::__lg(n);
        a.assign(n, std::vector<T>(lg + 1));
        for (int j = 0; j <= lg; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                a[i][j] = (j == 0 ? init[i] : std::min(a[i][j - 1], a[i + (1 << (j - 1))][j - 1], cmp));
            }
        }
    }
    T rangeMin(int l, int r) {
        int k = std::__lg(r - l);
        return std::min(a[l][k], a[r - (1 << k)][k], cmp);
    }
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		std::cin >> b[i];
	}

	std::vector<int> v(3 * n);
	for (int i = 0; i < 3 * n; i++) {
		v[i] = a[i % n];
	}

	RMQ<int, std::greater<int>> st(v);

	for (int i = 0; i < n; i++) {
		int lo = 1, hi = n;
		while (lo < hi) {
		    int m = (lo + hi) / 2;
		    if (st.rangeMin(n + i + 1, n + i + m + 1) >= b[i] || st.rangeMin(n + i - m, n + i) >= b[i]) {
		        hi = m;
		    } else {
		        lo = m + 1;
		    }
		}
		std::cout << (lo == n ? -1 : lo) << " \n"[i == n - 1];
	}

	return 0;
}