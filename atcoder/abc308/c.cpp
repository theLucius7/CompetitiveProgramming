#include <bits/stdc++.h>

bool cmp(std::pair<long double, int> &a, std::pair<long double, int> &b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first > b.first;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::vector<std::pair<long double, int>> X(N);
	for (int i = 0; i < N; i++) {
		long double A, B;
		std::cin >> A >> B;

		X[i] = std::make_pair(1.0 * A / (A + B), i + 1);
	}

	std::sort(X.begin(), X.end(), cmp);

	for (int i = 0; i < N; i++) {
		std::cout << X[i].second << " \n"[i == N - 1];
	}

	return 0;
}