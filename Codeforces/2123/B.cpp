#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, j, k;
	std::cin >> n >> j >> k;

	j--;
	
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	std::cout << ((k >= 2 || a[j] == *std::max_element(a.begin(), a.end())) ? "YES" : "NO") << "\n";
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