#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	i64 x;
	std::cin >> x;

	while (x % 2 == 0) {
		x /= 2;
	}

	i64 ans = 1;
	for (int i = 3; 1LL * i * i <= x; i += 2) {
		if (x % i == 0) {
			int cnt = 0;
			while (x % i == 0) {
				x /= i;
				cnt++;
			}

			ans *= cnt + 1;
		}
	}

	if (x > 1) {
		ans *= 2
	}


	std::cout << ans << "\n";

	return 0;
}