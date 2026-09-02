#include <bits/stdc++.h>

using i64 = long long;

#define int long long

constexpr int P = 998244353;

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string S;
	std::cin >> S;

	std::array<int, 3> dp{};
	int sum = 0;
	for (char c : S) {
		int ndp = (sum + 1) % P;
		sum = ((sum + ndp - dp[c - 'a']) % P + P) % P;
		dp[c - 'a'] = ndp;
	}
	std::cout << sum << "\n";

	return 0;
}