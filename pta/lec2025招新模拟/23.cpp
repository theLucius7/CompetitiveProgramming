#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < n; i++) {
		int a;
		std::cin >> a;

		if (a % 2 == 1) {
			cnt1++;
		} else {
			cnt2++;
		}
	}
	std::cout << cnt1 << " " << cnt2 << "\n";

	return 0;
}	