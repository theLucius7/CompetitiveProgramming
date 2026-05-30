#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	std::vector<i64> odd(5E5 + 10), even(5E5 + 10);
	odd[0] = 1, even[0] = 2;
	for (int i = 1; i < 50010; i++) {
		odd[i] = odd[i - 1] + 2 * i + 1;
		even[i] = even[i - 1] + 2 * i;
	}

	i64 a, b;
	std::cin >> a >> b;


	std::cout << std::min((std::upper_bound(odd.begin(), odd.end(), a) - odd.begin()) * 2 + 1, (std::upper_bound(even.begin(), even.end(), b) - even.begin()) * 2) + 1 << "\n";

	// std::cout << std::max(std::min((std::upper_bound(odd.begin(), odd.end(), a) - odd.begin()) * 2 + 1, (std::upper_bound(even.begin(), even.end(), b) - even.begin()) * 2) + 1, std::min((std::upper_bound(odd.begin(), odd.end(), b) - odd.begin()) * 2 + 1, (std::upper_bound(even.begin(), even.end(), a) - even.begin()) * 2) + 1) << "\n";
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