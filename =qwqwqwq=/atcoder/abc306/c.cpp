#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector<int> cnt(n + 1);
	for (int i = 1; i <= 3 * n; i++) {
		int x;
		std::cin >> x;
		cnt[x]++;
		if (cnt[x] == 2) {
			std::cout << x << " ";
		}
	}


	return 0;
}