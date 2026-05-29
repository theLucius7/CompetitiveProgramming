#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::string s;
	std::cin >> s;

	std::vector<std::array<int, 2>> pre(n + 1);
	for (int i = 0; i < n; i++) {
		pre[i + 1] = pre[i];
		if (s[i] == 'O') {
			pre[i + 1][0]++;
		} else {
			pre[i + 1][1]++;
		}
	}


	for (int i = 1; i < n; i++) {
		if (pre[i][0] * 2 != pre[n][0] && pre[i][1] * 2 != pre[n][1]) {
			std::cout << i << "\n";
			return 0;
		}
	}

	std::cout << -1 << "\n";

	return 0;
}