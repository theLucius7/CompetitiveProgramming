#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	std::cin >> n >> m;

	std::vector<std::string> S(n);
	for (int i = 0; i < n; i++) {
		std::cin >> S[i];
	}

	int cnt = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 1; j++) {
			if (S[i][j] == 'c' && S[i + 1][j] == 'p' && S[i][j + 1] == 'c' && S[i + 1][j + 1] == 'c') {
				cnt++;
			}
		}
	}
	std::cout << cnt << "\n";

	return 0;
}