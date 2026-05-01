#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::map<int, int> map;
	for (int i = 0; i < k; i++) {
		int b, c;
		std::cin >> b >> c;
		map[b] += c;
	}

	std::vector<int> v;
	for (auto [x, y] : map) {
		v.push_back(y);
	}
	std::sort(v.begin(), v.end(), std::greater<int>());

	std::cout << std::accumulate(v.begin(), std::min(v.end(), v.begin() + n), 0ll) << "\n";
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
