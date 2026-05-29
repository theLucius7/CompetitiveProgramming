#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1E8;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::vector<int> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}

	std::map<int, int> map3, map7;
	i64 ans = 0;
	for (int i = 0; i < N; i++) {
		if (A[i] % 5 == 0) {
			ans += 1LL * map3[A[i] / 5] * map7[A[i] / 5];
		}
		if (A[i] % 3 == 0) {
			map3[A[i] / 3]++;
		}
		if (A[i] % 7 == 0) {
			map7[A[i] / 7]++;
		}
	}

	map3.clear(), map7.clear();

	for (int i = N - 1; i >= 0; i--) {
		if (A[i] % 5 == 0) {
			ans += 1LL * map3[A[i] / 5] * map7[A[i] / 5];
		}
		if (A[i] % 3 == 0) {
			map3[A[i] / 3]++;
		}
		if (A[i] % 7 == 0) {
			map7[A[i] / 7]++;
		}
	}

	std::cout << ans << "\n";

	return 0;
}