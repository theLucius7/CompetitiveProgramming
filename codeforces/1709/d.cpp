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

	int n, m;
	std::cin >> n >> m;

	std::vector<int> a(m);
	for (int i = 0; i < m; i++) {
		std::cin >> a[i];
		a[i]--;
	}

	RMQ<int, std::greater<int>> st(a);

	int q;
	std::cin >> q;

	while (q--) {
		std::pair<int, int> x, y;
		std::cin >> x.first >> x.second >> y.first >> y.second;
		x.first--, x.second--, y.first--, y.second--;

		int k;
		std::cin >> k;

		int max = x.first + (n - 1 - x.first) / k * k;

		std::cout << ((st.rangeMin(std::min(x.second, y.second), std::max(x.second, y.second) + 1) < max && std::abs(x.first - y.first) % k == 0 && std::abs(x.second - y.second) % k == 0) ? "YES" : "NO") << "\n";
	}

	return 0;
}