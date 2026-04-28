#include <bits/stdc++.h>

using i64 = long long;
using real = long double;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, M;
	std::cin >> N >> M;

	std::map<std::pair<int, int>, bool> map;
	std::vector<int> cnt(N);
	for (int i = 0; i < M; i++) {
		int x, y;
		std::cin >> x >> y;	
		x--, y--;
		if (!map[{y, x}]) {
			cnt[y]++;
		} else {
			cnt[x]--;
		}
		map[{x, y}] = true;
	}

	int ans = 0;
	int max = -1;
	for (int i = 0; i < N; i++) {
		if (cnt[i] > max) {
			max = cnt[i];
			ans = i;
		}
	}
	std::cout << ans + 1 << " " << cnt[ans] << "\n";

	return 0;
}