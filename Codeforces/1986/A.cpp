#include <bits/stdc++.h>

using i64 = long long;

using real = long double;

void solve() {
	std::array<int, 3> a;
	for (int i = 0; i < 3; i++) {
		std::cin >> a[i];
	}

	std::cout << *std::max_element(a.begin(), a.end()) - *std::min_element(a.begin(), a.end()) << "\n";
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