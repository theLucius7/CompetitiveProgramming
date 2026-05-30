#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, K;
	std::cin >> N >> K;

	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		int x = i;
		int sum = 0;
		while (x) {
			sum += x % 10;
			x /= 10;
		}

		if (sum == K) {
			cnt++;
		}
	}

	std::cout << cnt << "\n";

	return 0;
}