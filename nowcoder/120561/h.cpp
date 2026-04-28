#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 P = 998244353;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	std::vector<i64> dp(n + 1);
	dp[0] = 1;
	std::vector<i64> pre(n + 2);
	pre[1] = 1;
	std::vector<i64> last(31, -1);

	i64 l = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 31; j++) {
			if ((a[i] >> j) & 1) {
				l = std::max(l, last[j] + 1);
				last[j] = i;
			}
		}
		dp[i + 1] = (pre[i + 1] - pre[l] + P) % P;
		pre[i + 2] = (pre[i + 1] + dp[i + 1] + P) % P;
	}

	std::cout << dp[n] << "\n";
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