#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::vector<std::string> S(N);
	for (int i = 0; i < N; i++) {
		std::cin >> S[i];
	}

	std::unordered_map<std::string, int> mp;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!mp[S[i] + S[j]] && i != j) {
				mp[S[i] + S[j]] = 1;
				ans++;
			}
		}
	}

	std::cout << ans << "\n";

	return 0;
}