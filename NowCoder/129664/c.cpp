#include <bits/stdc++.h>

using i64 = long long;
using real = long double;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	int lim = 0, max = 0;;
	for (int i = 0; i < N; i++) {
		std::string s;
		std::cin >> s;

		if (s == "/") {
			lim = 0;
			std::cout << max << "\n";
		} else {
			lim = std::stoi(s);
			std::cout << lim << "\n";
			int nx = (lim + 10) / 10 * 10;
			max = std::max(max, nx);
		}


	}

	return 0;
}