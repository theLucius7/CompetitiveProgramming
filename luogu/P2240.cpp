#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, T;
	std::cin >> N >> T;

	std::vector<std::pair<long double, int>> a(N);
	for (int i = 0; i < N; i++) {
		int m, v;
		std::cin >> m >> v;

		a[i].first = 1. * v / m;
		a[i].second = m;
	}

	std::sort(a.begin(), a.end(), std::greater<>());

	long double ans = 0;
	for (int i = 0; i < N; i++) {
		if (T >= a[i].second) {
			T -= a[i].second;
			ans += a[i].second * a[i].first;
		} else {
			ans += T * a[i].first;
			break;
		}
	}

	std::cout << std::fixed << std::setprecision(2) << ans << "\n";

	return 0;
}