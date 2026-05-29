#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, K;
	std::cin >> N >> K;

	for (int i = N; ; i++) {
		if (1LL * (N + i) * (i - N + 1) / 2 >= K) {
			std::cout << i - N << "\n";
			return 0;
		}
	}

	return 0;
}