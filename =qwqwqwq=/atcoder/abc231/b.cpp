#include <bits/stdc++.h>

using i64 = long long;

using real = long double;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::map<std::string, int> cnt;
	int max = 0;
	std::string ans;
	for (int i = 0; i < N; i++) {
		std::string s;
		std::cin >> s;
		cnt[s]++;
		if (cnt[s] > max) {
			ans = s;
			max = cnt[s];
		}
	}

	std::cout << ans << "\n";

	return 0;
}