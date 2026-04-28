#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::unordered_map<int, int> map;
	int max = 0, ans;
	for (int i = 0; i < N; i++) {
		int a;
		std::cin >> a;

		map[a]++;
		if (map[a] > max) {
			max = map[a];
			ans = a;
		}
	}

	std::cout << ans << " " << max << "\n";

	return 0;
}