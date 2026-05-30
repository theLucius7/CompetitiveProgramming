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

	int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (S[i][j] == '#') {
				int cnt = 0;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k], ny = j + dy[k];
					if (nx >= 0 && nx < H && ny >= 0 && ny < W && S[nx][ny] == '#') {
						cnt++;
					}
				}
				if (cnt != 2 && cnt != 4) {
					std::cout << "No\n";
					return 0;
				}
			}
		}
	}
	std::cout << "Yes\n";

	return 0;
}