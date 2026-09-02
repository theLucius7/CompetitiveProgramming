#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector<std::vector<int>> g(n);
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		std::cin >> x >> y;
		x--, y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	std::vector<int> c(n);
	for (int i = 0; i < n; i++) {
		std::cin >> c[i];
	}

	std::vector<std::vector<int>> adj(n);
	std::vector<int> siz(n), in(n), out(n), ord(n);
	int cur = 0;
	[&](this auto &&self, int x, int p) -> void{
		for (int y : g[x]) {
			if (y != p) {
				adj[x].push_back(y);
			}
		}

		siz[x] = 1;
		in[x] = cur++;
		ord[in[x]] = x;
		for (auto &y : adj[x]) {
			self(y, x);
			siz[x] += siz[y];
			if (siz[y] > siz[adj[x][0]]) {
				std::swap(y, adj[x][0]);
			}
		}
		out[x] = cur;
	} (0, -1);

	std::vector<int> cnt(n);
	int unqCnt = 0;
	auto add = [&](int c, int t) {
		if (t == 1) {
			if (cnt[c]) {
				cnt[c]++;
			} else {
				cnt[c]++;
				unqCnt++;
			}
		} else {
			if (cnt[c] > 1) {
				cnt[c]--;
			} else {
				cnt[c]--;
				unqCnt--;
			}
		}
	};

	auto calc = [&](int x, int t) {
		for (int i = in[x]; i < out[x]; i++) {
			add(c[ord[i]], t);
		}
	};

	std::vector<int> ans(n);
	[&](this auto &&self, int x) -> void {
		for (auto y : adj[x]) {
			if (y != adj[x][0]) {
				self(y);
				calc(y, -1);
			}
		}

		if (!adj[x].empty()) {
			self(adj[x][0]);
		}

		for (auto y : adj[x]) {
			if (y != adj[x][0]) {
				calc(y, 1);
			}
		}
		add(c[x], 1);
		ans[x] = unqCnt;
	}(0);

	int m;
	std::cin >> m;

	for (int i = 0; i < m; i++) {
		int x;
		std::cin >> x;
		x--;
		std::cout << ans[x] << "\n";
	}

	return 0;
}