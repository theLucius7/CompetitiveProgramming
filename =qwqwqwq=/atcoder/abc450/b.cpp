#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::map<std::pair<int, int>, int> c;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			std::cin >> c[{i, j}];
		}
	}

	for (int i = 1; i < N - 1; i++) {
		for (int j = 0; j < i; j++) {
			for (int k = i + 1; k < N; k++) {
				if (c[{j, i}] + c[{i, k}] < c[{j, k}]) {
					std::cout << "Yes\n";
					return 0;
				}
			}
		}
	}

	std::cout << "No\n";


	return 0;
}