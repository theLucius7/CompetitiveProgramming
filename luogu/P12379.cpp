#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string s;
	std::cin >> s;

	std::vector<int> dp(s.size());
	for (int i = 0; i < s.size(); i++) {
		if (i == 0) {
			dp[i] = s[i] - 'a' + 1;
		} else if (i == 1) {
			dp[i] = std::max(dp[i - 1], s[i] - 'a' + 1);
		} else {
			dp[i] = std::max(dp[i - 1], dp[i - 2] + (s[i] - 'a' + 1));
		}
	}
	std::cout << dp[s.size() - 1] << "\n";

	return 0;
}