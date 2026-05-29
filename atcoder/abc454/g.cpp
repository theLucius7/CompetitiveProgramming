#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, seed, M, F;
	std::cin >> N >> seed >> M >> F;

	i64 state = seed;

	std::vector<int> p(N);
	for (int i = 1; i < N; i++) {
		if (i < M) {
			std::cin >> p[i];
			p[i]--;
		} else {
			p[i] = state % i;
			state = (state * 1103515245 + 12345) % (1LL << 31);
		}
	}

	std::vector<int> c(N);
	for (int i = 0; i < N; i++) {
		if (i < M) {
			std::cin >> c[i];
			c[i]--;
		} else {
			c[i] = state % F;
			state = (state * 1103515245 + 12345) % (1LL << 31);
		}
	}

	std::vector<std::vector<int>> adj(N);
	for (int i = 1; i < N; i++) {
		adj[p[i]].push_back(i);
	}

	std::vector<int> siz(N), in(N), out(N), ord(N);
	int cur = 0;
	[&](this auto &&self, int x) -> void {
		siz[x] = 1;
		in[x] = cur++;
		ord[in[x]] = x;
		for (int &y : adj[x]) {
			self(y);
			siz[x] += siz[y];
			if (siz[y] > siz[adj[x][0]]) {
				std::swap(y, adj[x][0]);
			}
		}
		out[x] = cur;
	} (0);

	std::vector<int> cnt(N), freq(N + 1);
	freq[0] = N;

	int m = 0;
	auto add = [&](int c, int t) {
		freq[cnt[c]]--;
		cnt[c] += t;
		freq[cnt[c]]++;
		m = std::max(m, cnt[c]);
		if (!freq[m]) {
			m--;
		}
	};

	auto calc = [&](int x, int t) {
		for (int i = in[x]; i < out[x]; i++) {
			add(c[ord[i]], t);
		}
	};

	int ans = 0;
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
		ans = (ans + i64(m ^ (x + 1)) * (freq[m] ^ (x + 1))) % 998244353;
	} (0);

	std::cout << ans << "\n";

	return 0;
}