#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::string s;
	std::cin >> s;

	int r = std::sqrt(n);

	if (r * r != n) {
		std::cout << "No\n";
		return;
	}

	auto calc = [&](int x, int y) {
		return x * r + y;
	};

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < r; j++) {
			if (i == 0 || i == r - 1) {
				if (s[calc(i, j)] == '0') {
					std::cout << "No\n";
					return;
				}
			} else {
				if (j == 0 || j == r - 1) {
					if (s[calc(i, j)] == '0') {
						std::cout << "No\n";
						return;
					}
				} else {
					if (s[calc(i, j)] == '1') {
						std::cout << "No\n";
						return;
					}
				}
			}
			// std::cout << s[calc(i, j)] << " \n"[j == r - 1];
		}
	}
	std::cout << "Yes\n";

}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}


	return 0;
}