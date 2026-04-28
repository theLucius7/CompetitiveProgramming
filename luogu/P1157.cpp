#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, r;
	std::cin >> n >> r;

	std::vector<int> a;
	auto dfs = [&](auto self, int x, int cnt) -> void {
		if (x != 0) {
			a.push_back(x);
		}
		if (cnt == r) {
			for (int i = 0; i < r; i++) {
				std::cout << std::setw(3) << a[i];
			}
			std::cout << "\n";
			return;
		}

		for (int y = x + 1; y <= n; y++) {
			self(self, y, cnt + 1);
			a.pop_back();
		}
	};
	dfs(dfs, 0, 0);

	return 0;
}