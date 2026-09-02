#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int H, W;
	std::cin >> H >> W;

	std::vector<std::string> S(H);
	for (int i = 0; i < H; i++) {
		std::cin >> S[i];
	}

	int cnt = 0;
	for (int h1 = 0; h1 < H; h1++) {
		for (int h2 = h1; h2 < H; h2++) {
			for(int w1 = 0; w1 < W; w1++) {
				for (int w2 = w1; w2 < W; w2++) {
					bool ok = true;
					for (int i = h1; i <= h2; i++) {
						for (int j = w1; j <= w2; j++) {
							if (S[i][j] != S[h1 + h2 - i][w1 + w2 - j]) {
								ok = false;
								break;
							}
						}
						if (!ok) {
							break;
						}
					}
					cnt += ok;
				}
			}
		}
	}
	std::cout << cnt << "\n";

	return 0;
}
