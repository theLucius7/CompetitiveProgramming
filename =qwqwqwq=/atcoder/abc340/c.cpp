#include <bits/stdc++.h>

using i64 = long long;

i64 sum = 0;

std::map<i64, i64> mp;

i64 dfs(i64 x) {
	if (x < 2) {
		return 0;
	}

	if ()

	dfs((x + 1)/2) + dfs(x/2);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	i64 x;
	std::cin >> x;

	dfs(x);

	std::cout << sum << "\n";

	return 0;
}