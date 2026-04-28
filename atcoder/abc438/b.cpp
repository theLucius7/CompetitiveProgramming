#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, M;
	std::cin >> N >> M;

	std::string S, T;
	std::cin >> S >> T;

	int max = 1E8 + 10;
	for (int i = 0; i + M - 1 < N; i++) {
		int res = 0;
		for (int j = 0; j < M; j++) {
			res += (10 + S[i + j] - T[j]) % 10;
		}
		max = std::min(max, res);
	}
	std::cout << max << "\n";


	return 0;
}