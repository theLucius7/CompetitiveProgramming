#include <bits/stdc++.h>

using i64 = long long;

int binom[2010][2010];
int pre[2010][2010];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t, k;
	std::cin >> t >> k;

	for (int i = 0; i <= 2000; i++) {
		binom[i][0] = 1;
	}
	for (int i = 1; i <= 2000; i++) {
		for (int j = 1; j <= i; j++) {
			binom[i][j] = (binom[i - 1][j] + binom[i - 1][j - 1]) % k;
		}
	}


	for (int i = 0; i <= 2000; i++) {
		for (int j = 0; j <= 2000; j++) {
			pre[i + 1][j + 1] = pre[i][j + 1] + pre[i + 1][j] - pre[i][j] + (binom[i][j] == 0 && j <= i);
		}
	}

	while (t--) {
		int n, m;
		std::cin >> n >> m;

		std::cout << pre[n + 1][m + 1] << "\n";
	}

	return 0;
}