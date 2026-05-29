#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::vector<std::vector<int>> a(3, std::vector<int>(N));
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> a[i][j];
		}
	}

	std::map<int, std::set<int>> map;
	std::array<std::vector<int>, 3> cnt;
	for (int i = 0; i < 3; i++) {
		cnt[i].resize(N + 1, 0);
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < N; j++) {
			map[a[i][j]].insert(j);
			cnt[i][a[i][j]]++;
		}
	}

	std::queue<int> q;
	std::vector<bool> vis(N);
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (cnt[0][i] == 0 || cnt[1][i] == 0 || cnt[2][i] == 0) {
			for (auto j : map[i]) {
				if (!vis[j]) {
					q.push(j);
					ans++;
					vis[j] = true;
				}
			}
		}
	}

	while (!q.empty()) {
		int t = q.front();
		q.pop();
		cnt[0][a[0][t]]--, cnt[1][a[1][t]]--, cnt[2][a[2][t]]--;
		if (cnt[0][a[0][t]] == 0) {
			for (auto j : map[a[0][t]]) {
				if (!vis[j]) {
					q.push(j);
					ans++;
					vis[j] = true;
				}
			}
		}
		if (cnt[1][a[1][t]] == 0) {
			for (auto j : map[a[1][t]]) {
				if (!vis[j]) {
					q.push(j);
					ans++;
					vis[j] = true;
				}
			}
		}
		if (cnt[2][a[2][t]] == 0) {
			for (auto j : map[a[2][t]]) {
				if (!vis[j]) {
					q.push(j);
					ans++;
					vis[j] = true;
				}
			}
		}
	}

	std::cout << ans << "\n";


	return 0;
}