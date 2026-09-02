#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, M;
	std::cin >> N >> M;

	std::vector<std::array<int, 2>> cnt(M);
	for (int i = 0; i < N; i++) {
		int A, B;
		std::cin >> A >> B;
		A--, B--;
		cnt[A][0]++;
		cnt[B][1]++;
	}

	for (int i = 0; i < M; i++) {
		std::cout << cnt[i][1] - cnt[i][0] << "\n";
	}

	return 0;
}