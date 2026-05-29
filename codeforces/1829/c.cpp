#include <bits/stdc++.h>

constexpr int inf = 1E9;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> f(4, inf);

	int a = inf, b = inf, c = inf;
	for (int i = 0; i < n; i++) {
		int m;
		std::string s;
		std::cin >> m >> s;
		int t = (s[0] - '0') << 1 | (s[1] - '0');
		f[t] = std::min(f[t], m);
	}

	int ans = std::min(f[1]	 + f[2], f[3]);
	if (ans == inf) {
		ans = -1;
	}
	std::cout << ans << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;
	while(t--) {
		solve();
	}

	return 0;
}