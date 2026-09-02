#include <bits/stdc++.h>

using i64 = long long;

using real = long double;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int H, W, Q;
	std::cin >> H >> W >> Q;

	while (Q--) {
		int op;
		std::cin >> op;

		if (op == 1) {
			int R;
			std::cin >> R;
			std::cout << R * W << "\n";
			H -= R;
		} else {
			int C;
			std::cin >> C;
			std::cout << C * H << "\n";
			W -= C;
		}
	}

	return 0;
}