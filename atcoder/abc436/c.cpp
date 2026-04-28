#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, M;
	std::cin >> N >> M;

	std::map<std::pair<int, int>, bool> map;
	int dx[] = {1, 0, 1, 0}, dy[] = {0, 0, 1, 1};
	for (int i = 0; i < M; i++) {
		int r, c;
		std::cin >> r >> c;
		r--, c--;

		bool ok = true;
		for (int k = 0; k < 4; k++) {
			int nr = r + dx[k], nc = c + dy[k];
			if (nr < 0 || nr >= N || map.contains({nr, nc})) {
				ok = false;
				break;
			}
		}

		if (ok) {
			for (int k = 0; k < 4; k++) {
				int nr = r + dx[k], nc = c + dy[k];
				map[{nr, nc}] = true;
			}
		}
	}

	std::cout << map.size() / 4 << "\n";

	return 0;
}

