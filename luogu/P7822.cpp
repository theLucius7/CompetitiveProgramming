#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	constexpr i64 P = 1E9 + 7;

	int n, m;
	std::cin >> n >> m;

	std::vector<int> a(m);
	for (int i = 0; i < m; i++) {
		std::cin >> a[i];
	}

	// std::vector dp(n + 1, std::vector<i64>(m));
	std::vector s(m, std::vector<int>(n + 2));
	std::vector<i64> sum(n + 2);

	sum[1] = 1;

	for (int i = 1; i <= n; i++) {
		i64 cur = 0;
		i64 all = 0;
		for (int j = 0; j < m; j++) {
			if (i >= a[j]) {
				cur = sum[i] - sum[i - a[j]] - (s[j][i] - s[j][i - a[j]]);
				cur = (cur % P + P) % P;
			} else {
				cur = sum[i] - s[j][i];
				cur = (cur % P + P) % P;
			}
			s[j][i + 1] = (s[j][i] + cur) % P;
			all += cur;
			all %= P;
		}
		sum[i + 1] = sum[i] + all;
		sum[i + 1] %= P;
	}

	std::cout << ((sum[n + 1] - sum[n]) % P + P) % P << "\n";


	return 0;
}