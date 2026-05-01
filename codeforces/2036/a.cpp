#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	for (int i = 1; i < n; i++) {
		if (std::abs(a[i] - a[i - 1]) != 5 && std::abs(a[i] - a[i - 1]) != 7) {
			std::cout << "No\n";
			return;
		}
	}
	std::cout << "Yes\n";
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
