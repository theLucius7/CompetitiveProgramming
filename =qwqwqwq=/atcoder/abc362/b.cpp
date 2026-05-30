#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1E8;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<int> X(3), Y(3);
	for (int i = 0; i < 3; i++) {
		std::cin >> X[i] >> Y[i];
	}

	std::vector<int> d;
	for (int i = 0; i < 3; i++) {
		for (int j = i + 1; j < 3; j++) {
			d.push_back(std::pow(std::abs(X[i] - X[j]), 2) + std::pow(std::abs(Y[i] - Y[j]), 2));
		}
	}

	std::sort(d.begin(), d.end());

	// std::cout << d[0] << " " << d[1] << " " << d[2] << "\n";

	std::cout << (d[0] + d[1] == d[2] ? "Yes" : "No") << "\n";


	return 0;
}