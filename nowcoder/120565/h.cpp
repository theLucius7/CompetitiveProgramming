#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector<i64> sum(2);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			i64 a;
			std::cin >> a;
			sum[(i + j) % 2] += a;
		}
	}

	std::cout << (sum[0] == sum[1] ? "Yes" : "No") << "\n";

	return 0;
}