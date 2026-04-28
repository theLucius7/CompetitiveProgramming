#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::vector<int> a(N);
	for (int i = 0; i < N; i++) {
		std::cin >> a[i];
	}

	std::swap(a[0], *std::min_element(a.begin(), a.end()));
	std::swap(a[N - 1], *std::max_element(a.begin(), a.end()));
	for (int i = 0; i < N; i++) {
		std::cout << a[i] << " \n"[i == N - 1];
	}

	return 0;
}