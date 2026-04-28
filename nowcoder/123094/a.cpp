#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> p(n);
	std::vector<std::vector<int>> adj(n);
	for (int i = 0; i < n; i++) {
		std::cin >> p[i];
		p[i]--;
		adj[i].push_back(p[i]);
	}

	std::vector<int> ans(n);
	std::vector<bool> vis(n);
	std::vector<int> v;
	auto dfs = [&](auto self, int x, int cnt) {
		vis[x] = true;
		v.push_back(x);
		for (auto y : adj[x]) {
			if (vis[y]) {
				for (int i = 0; i < v.size(); i++) {
					ans[v[i]] = cnt;
				}
				return;
			} else {
				self(self, y, cnt + 1);
			}
		}
	};

	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			v.clear();
			dfs(dfs, i, 1);
		}
	}

	for (int i = 0; i < n; i++) {
		std::cout << ans[i] << " \n"[i == n - 1];
	}

}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}


	return 0;
}