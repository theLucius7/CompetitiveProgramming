#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::vector<int> T(N);
	for (int i = 0; i < N; i++) {
		std::cin >> T[i];
	}

	std::pair<int, std::vector<int>> max{0, {}};
	int cnt = 0;
	std::vector<bool> vis(N);
	int ans = 0;
	for (int x = 0, y = -1; x <= N; x++) {
		if (x < N && T[x] < 0) {
			cnt++;
		} else {
			for (int i = y; i >= std::max(0, y - 2 * cnt + 1); i--) {
				if (!vis[i]) {
					vis[i] = true;
					ans++;
				}
			}
			if (cnt > max.first) {
				max = {cnt, {y - 2 * cnt}};
			} else if (cnt == max.first) {
				max.second.push_back(y - 2 * cnt);
			}
			cnt = 0;
			y = x;
		}
	}

	int maxcnt = 0;
	for (auto x : max.second) {
		int ncnt = 0;
		for (int i = x; i >= std::max(0, x - max.first + 1); i--) {
			if (!vis[i]) {
				ncnt++;
			}
		}
		maxcnt = std::max(maxcnt, ncnt);
	}
	std::cout << ans + maxcnt << "\n";


	return 0;
}