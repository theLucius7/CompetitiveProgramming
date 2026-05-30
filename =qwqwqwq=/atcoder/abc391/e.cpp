#include <bits/stdc++.h>

using i64 = long long;

#define int long long

constexpr int inf = 1E18;

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::string A;
	std::cin >> A;

	auto dfs = [&](this auto &&self, int l, int r) -> std::pair<int, int> {
		int len = r - l + 1;
		if (len == 1) {
			int x = A[l] - '0';
			return {x, 1};
		}

		std::vector<std::pair<int, int>> v(3);

		v[0] = self(l, l + len / 3 - 1);
		v[1] = self(l + len / 3, l + len / 3 + len / 3 - 1);
		v[2] = self(r - len / 3 + 1, r);

		// std::cout << l << " " << l + len / 3 - 1 << "\n";
		// std::cout << l + len / 3 << " " << l + len / 3 + len / 3 - 1 << "\n";
		// std::cout << r - len / 3 + 1 << " " << r << "\n";

		std::vector<int> cnt(2);
		for (int i = 0; i < 3; i++) {
			cnt[v[i].first]++;
		}

		// 0 0 1   0 1 0    0 1 1    1 0 0   1 0 1  1 1 0 111  

		if (cnt[0] > cnt[1]) {
			if (cnt[0] == 2) {
				int min = inf;
				for (int i = 0; i < 3; i++) {
					if (v[i].first == 0) {
						min = std::min(min, v[i].second);
					}
				}
				return {0, min};
			} else {
				int sum = 0, max = -1;
				for (int i = 0; i < 3; i++) {
					if (v[i].first == 0) {
						sum += v[i].second;
						max = std::max(max, v[i].second);
					}
				}
				return {0, sum - max};
			}
		} else {
			if (cnt[1] == 2) {
				int min = inf;
				for (int i = 0; i < 3; i++) {
					if (v[i].first == 1) {
						min = std::min(min, v[i].second);
					}
				}
				return {1, min};
			} else {
				int sum = 0, max = -1;
				for (int i = 0; i < 3; i++) {
					if (v[i].first == 1) {
						sum += v[i].second;
						max = std::max(max, v[i].second);
					}
				}
				return {1, sum - max};
			}
		}
	};

	std::cout << dfs(0, std::pow(3, N) - 1).second << "\n";


	return 0;
}