#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<std::pair<int, int>> P(2);
	std::cin >> P[0].first >> P[0].second >> P[1].first >> P[1].second;

	int N;
	std::cin >> N;

	std::vector<std::pair<int, int>> dis(N);
	for (int i = 0; i < N; i++) {
		int x, y;
		std::cin >> x >> y;

		dis[i].first = (x - P[0].first) * (x - P[0].first) + (y - P[0].second) * (y - P[0].second);
		dis[i].second = (x - P[1].first) * (x - P[1].first) + (y - P[1].second) * (y - P[1].second);
	}

	std::sort(dis.begin(), dis.end());

	int ans = dis[N - 1].first;
	int b = 0;
	for (int i = N - 1; i >= 0; i--) {
		b = std::max(b, dis[i].second);
		if (i == 0) {
			ans = std::min(ans, b);
			continue;
		}
		ans = std::min(ans, dis[i - 1].first + b);
	}
	std::cout << ans << "\n";


	return 0;
}