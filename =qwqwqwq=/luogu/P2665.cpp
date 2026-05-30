#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::vector<int> X(N), Y(N);
	for (int i = 0; i < N; i++) {
		std::cin >> X[i] >> Y[i];
	}

	std::set<long double> set;
	bool ok = false;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (X[j] - X[i] == 0) {
				ok = true;
				continue;
			}
			set.insert(1. * (Y[j] - Y[i]) / (X[j] - X[i]));
		}
	}
	std::cout << set.size() + ok << "\n";

	return 0;
}