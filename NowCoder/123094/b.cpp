#include <bits/stdc++.h>

#define int long long

using i64 = long long;

constexpr i64 inf = 1E18 + 1;

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, k, m;
	std::cin >> n >> k >> m;

	std::vector<std::string> s(n);
	std::unordered_map<std::string, int> cost;
	for (int i = 0; i < n; i++) {
		std::cin >> s[i];
	}

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		cost[s[i]] = a[i];
	}

	for (int i = 0; i < k; i++) {
		int x;
		std::cin >> x;

		std::vector<int> b(x);
		int min = inf;
		for (int j = 0; j < x; j++) {
			std::cin >> b[j];
			b[j]--;
			min = std::min(min, a[b[j]]);
		}

		for (int j = 0; j < x; j++) {
			cost[s[b[j]]] = min;
		}
	}

	int ans = 0;
	for (int i = 0; i < m; i++) {
		std::string t;
		std::cin >> t;
		ans += cost[t];
	}
	std::cout << ans << "\n";

	return 0;
}