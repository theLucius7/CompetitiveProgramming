#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int Q;
	std::cin >> Q;

	std::queue<std::array<int, 2>> q;

	while(Q--) {
		int a;
		std::cin >> a;

		if (a == 1) {
			int c, x;
			std::cin >> c >> x;

			q.push({c, x});
		} else {
			int k;
			std::cin >> k;

			i64 sum = 0;
			while (k) {
				if (q.front()[0] > k) {
					q.front()[0] -= k;
					sum += 1LL * k * q.front()[1];
					k = 0;
				} else {
					sum += 1LL * q.front()[0] * q.front()[1];
					k -= q.front()[0];
					q.pop();
				}
			}
			std::cout << sum << "\n";
		}
	}

	return 0;
}