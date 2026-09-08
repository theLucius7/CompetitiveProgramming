#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < 3; j++) {
			int x;
			std::cin >> x;
			sum += x;
		}
		cnt += (sum >= 2);
	}
	std::cout << cnt << "\n";


	return 0;
}