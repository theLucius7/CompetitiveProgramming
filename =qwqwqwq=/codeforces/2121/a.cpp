#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1E8 + 1;

void solve() {
	int n, s;
	std::cin >> n >> s;

	int min = inf, max = -inf;
	for (int i = 0; i < n; i++) {
		int a;
		std::cin >> a;
		min = std::min(min, a);
		max = std::max(max, a);
	}

	std::cout << std::min(std::abs(s - min), std::abs(s - max)) + max - min << "\n";
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