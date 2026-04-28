#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	std::cin >> n >> m;

	std::vector<bool> ok(n - 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		std::cin >> a >> b;
		a--;
		b--;

		if (a > b) {
			std::swap(a, b);
		}

		if (b == a + 1) {
			ok[a] = true;
		}
	}

	for (int i = 0; i < n - 1; i++) {
		if (!ok[i]) {
			std::cout << "No\n";
			return 0;
		}
	}
	std::cout << "Yes\n";


	return 0;
}