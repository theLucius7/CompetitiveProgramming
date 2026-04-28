#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 P = 998244353;

void solve() {
	int n;
	std::cin >> n;

	std::map<int, int> cnt;
	for (int i = 0; i < n; i++) {
		int a;
		std::cin >> a;
		cnt[a]++;
	}

	std::vector<int> f;
	int max = 0;
	i64 res = 1;
	for (auto [k, v] : cnt) {
		f.push_back(v);
		res *= (v + 1);
		max = std::max(max, v);
		res %= P;
	}

	std::vector<i64> dp(n + 1);
	dp[0] = 1;
	for (int x : f) {
		for (int y = n; y >= x; y--) {
			dp[y] += (i64)x * dp[y - x];
			dp[y] %= P;
		}
	}

	i64 sum = 0;
	for (int i = 0; i < max; i++) {
		sum += dp[i];
		sum %= P;
	}

	std::cout << (res - sum + P) % P << "\n";
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