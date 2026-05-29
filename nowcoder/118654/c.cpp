#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	i64 n;
	std::cin >> n;

	int ans = 0;
	while (true) {
		if (n == 2) {
			std::cout << ans << "\n";
			return 0;
		}

		int cnt = 0;
		for (int i = 1; i * i <= n; i++) {
			if (n % i == 0) {
				if (n / i == i) {
					cnt++;
				} else {
					cnt += 2;
				}
			}
		}
		n = cnt;
		ans++;
	}

	return 0;
}