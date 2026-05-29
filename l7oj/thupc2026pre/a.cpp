#include <bits/stdc++.h>

using i64 = long long;

using real = long double;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string s;
	std::cin >> s;

	const int n = s.size();
	real p = 1;
	real ans = 0;
	for (int i = 0; i < n; i++) {
		ans += p * ((n - i - 1) * 0.9 + 1) * (s[i] - '0');
		p *= 0.1;
	}
	std::cout << std::fixed << std::setprecision(10) << ans << "\n";

	return 0;
}