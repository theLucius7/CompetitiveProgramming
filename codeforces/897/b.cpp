#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int k, p;
	std::cin >> k >> p;

	i64 ans = 0;
	for (int i = 1; i <= k; i++) {
		std::string s = std::to_string(i);
		s += std::string(s.rbegin(), s.rend());
		ans = (ans + std::stoll(s) % p) % p;
	}
	std::cout << ans << "\n";

	return 0;
}