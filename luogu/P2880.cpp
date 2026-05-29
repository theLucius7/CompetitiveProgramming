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

	int n, q;
	std::cin >> n >> q;

	std::vector<int> h(n);
	for (int i = 0; i < n; i++) {
		std::cin >> h[i];
	}

	RMQ<int, std::less<int>> stMin(h);
	RMQ<int, std::greater<int>> stMax(h);
	while (q--) {
		int l, r;
		std::cin >> l >> r;
		l--, r--;
		std::cout << stMax.rangeMin(l, r + 1) - stMin.rangeMin(l, r + 1) << "\n";
	}

	return 0;
}