#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::map<std::pair<std::string, std::string>, int> cnt;
	i64 ans = 0;
	for (int i = 0; i < N; i++) {
		std::string S, T;
		std::cin >> S >> T;
		if (S.substr(0, 2) == T.substr(0, 2)) {
			continue;
		}

		ans += cnt[{S.substr(0, 2), T.substr(0, 2)}];
		cnt[{T.substr(0, 2), S.substr(0, 2)}]++;
	}
	std::cout << ans << "\n";

	return 0;
}