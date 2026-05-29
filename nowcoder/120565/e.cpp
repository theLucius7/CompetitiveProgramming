#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	i64 P;
	std::cin >> n >> P;

	i64 pre = 0;
	std::set<std::pair<i64, int>> set;
	set.insert({0, 0});

	i64 max = 0;
	std::pair<int, int> ans;
	for (int i = 0; i < n; i++) {
		i64 a;
		std::cin >> a;

		pre += a;
		pre %= P;

		if (pre > max) {
			max = pre;
			ans = {0, i};
		}

		auto it = set.upper_bound({pre, n + 5});
		if (it != set.end() && (pre - (*it).first + P) % P > max) {
			max = (pre - (*it).first + P) % P;
			ans = {(*it).second, i};
		}

		set.insert({pre, i + 1});
	}

	std::cout << ans.first << " " << ans.second << " " << max << "\n";

	return 0;
}