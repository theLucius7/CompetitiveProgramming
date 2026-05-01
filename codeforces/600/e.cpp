#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	
	int n;
	std::cin >> n;

	std::vector<int> c(n);
	for (int i = 0; i < n; i++) {
		std::cin >> c[i];
	}

	std::vector<std::vector<int>> g(n);
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		std::cin >> x >> y;
		x--, y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	std::vector<std::vector<int>> adj(n);
	std::vector<int> siz(n), in(n), out(n), ord(n);
	int cur = 0;
	[&](this auto &&self, int x, int p) -> void {
		for (auto y : g[x]) {
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

	std::vector<int> cnt(n + 1);
	std::vector<i64> sum(n + 1);
	sum[0] = 1LL * n * (n + 1) / 2;
	int m = 0;
	auto add = [&](int c, int t) {
		sum[cnt[c]] -= c;
		cnt[c] += t;
		sum[cnt[c]] += c;
		m = std::max(m, cnt[c]);
		if (!sum[m]) {
			m--;
		}
	};

	auto calc = [&](int x, int t) {
		for (int i = in[x]; i < out[x]; i++) {
			add(c[ord[i]], t);
		}
	};

	std::vector<i64> ans(n);
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
		ans[x] = sum[m];
	} (0);

	for (int i = 0; i < n; i++) {
		std::cout << ans[i] << " \n"[i == n - 1];
	}

	return 0;
}