#include <bits/stdc++.h>

using i64 = long long;
using real = long double;

std::unordered_map<char, int> umap;


void solve() {
	std::string s;
	std::cin >> s;

	int max = 0;
	i64 ans = 0;

	for (int i = s.size() - 1; i >= 0; i--) {
		if (umap[s[i]] >= max) {
			ans += umap[s[i]];
		} else {
			ans -= umap[s[i]];
		}
		max = std::max(max, umap[s[i]]);
	}
	std::cout << ans << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	umap['I'] = 1;
	umap['V'] = 5;
	umap['X'] = 10;
	umap['L'] = 50;
	umap['C'] = 100;
	umap['D'] = 500;
	umap['M'] = 1000;

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}