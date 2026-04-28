#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	i64 T;
	std::cin >> n >> T;

	std::vector<i64> t(n);
	for (int i = 0; i < n; i++) {
		std::cin >> t[i];
	}

	i64 max = *std::max_element(t.begin(), t.end());

	std::cout << std::max(2LL, max / T + (max % T != 0)) << "\n";

	return 0;
}