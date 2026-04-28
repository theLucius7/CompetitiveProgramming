#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int H, W;
	std::cin >> H >> W;

	for (int x = 0; x < H; x++) {
		for (int y = 0; y < W; y++) {
			if (x == 0 || x == H - 1 || y == 0 || y == W - 1) {
				std::cout << '#';
			} else {
				std::cout << '.';
			}
		}
		std::cout << "\n";
	}

	return 0;
}	