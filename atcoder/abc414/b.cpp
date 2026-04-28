#include <bits/stdc++.h>

using i64 = long long;


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	i64 sum = 0;
	for (int i = 0; i < N; i++) {
		char c;
		i64 l;
		std::cin >> c >> l;

		sum += l;
		if (sum > 100) {
			std::cout << "Too Long\n";
			return 0;
		}
		for (int j = 0; j < l; j++) {
			std::cout << c;
		}
	}


	return 0;
}