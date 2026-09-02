#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1E9 + 1;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<int>> adj(n);
	std::vector<int> cnt(n);
	for (int i = 0; i < m; i++) {
		int x, y;
		std::cin >> x >> y;
		x--, y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
		cnt[x]++;
		cnt[y]++;
	}

	std::vector<std::pair<int, int>> w;
	for (int i = 0; i < n; i++) {
		w.emplace_back(cnt[i], i);
	}

	std::sort(w.begin(), w.end(), std::greater<>());

	std::vector<int> ans(n, inf);
	std::queue<int> q;

	auto bfs = [&]() {
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (auto y : adj[x]) {
				if (cnt[y] <= cnt[x] && ans[y] > ans[x] + 1) {
					q.push(y);
					ans[y] = ans[x] + 1;
				}
			}
		}
	};

	int cur = w[0].first;
	for (int i = 0; i < n; i++) {
		if (w[i].first == cur) {
			ans[w[i].second] = 0;
			q.push(w[i].second);
		} else {
			bfs();
			cur = w[i].first;
		}
	}

	for (int i = 0; i < n; i++) {
		std::cout << (ans[i] == 0 || ans[i] == inf ? -1 : ans[i]) << " \n"[i == n - 1];
	}


	return 0;
}