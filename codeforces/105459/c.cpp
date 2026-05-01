#include <bits/stdc++.h>

using i64 = long long;

using namespace std;

void solve() {
	int n;
	std::cin >> n;

	char c, nc;
	for (int i = 0; i < n; i++) {
		std::cin >> nc;

		int x;
		std::cin >> x;

		if (i == 0) {
			std::cout << 2 * (n - 1) + 1 << " " << nc << "\n";
		} else {
			if (nc == 'W') {
				if (c == 'N') {
					std::cout << "L\n";
				} else {
					std::cout << "R\n";
				}
			} else if (nc == 'S') {
				if (c == 'W') {
					std::cout << "L\n";
				} else {
					std::cout << "R\n";
				}
			} else if (nc == 'E') {
				if (c == 'S') {
					std::cout << "L\n";
				} else {
					std::cout << "R\n";
				}
			} else if (nc == 'N') {
				if (c == 'E') {
					std::cout << "L\n";
				} else {
					std::cout << "R\n";
				}
			}
		}
		std::cout << "Z " << x << "\n";

		c = nc;
	}
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