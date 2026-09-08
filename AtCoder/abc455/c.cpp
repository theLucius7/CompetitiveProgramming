#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, K;
	std::cin >> N >> K;

	std::map<int, i64> map;
	for (int i = 0; i < N; i++) {
		int A;
		std::cin >> A;
		map[A] += A;
	}

	std::vector<std::pair<i64, int>> v;
	for (auto [key, val] : map) {
		v.emplace_back(val, key);
	}

	std::sort(v.begin(), v.end());


	i64 ans = 0;
	for (int i = 0; i < (int)v.size() - K; i++) {
		ans += v[i].first;
	}

	std::cout << ans << "\n";

	

	return 0;
}
