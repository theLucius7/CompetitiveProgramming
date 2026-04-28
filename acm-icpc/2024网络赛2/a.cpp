#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	std::cin >> n >> m;

	int min = INT_MAX;
	for (int i = 0; i < m; i++) {
		int c;
		std::cin >> c;
		min = std::min(min, c);
	}



	return 0;
}
