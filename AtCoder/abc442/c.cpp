#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, M;
	std::cin >> N >> M;

	std::vector<int> cnt(N);
	for (int i = 0; i < M; i++) {
		int A, B;
		std::cin >> A >> B;
		A--, B--;
		cnt[A]++, cnt[B]++;
	}

	for (int i = 0; i < N; i++) {
		int x = N - 1 - cnt[i];
		std::cout << 1LL * x * (x - 1) * (x - 2) / 6 << " \n"[i == N - 1];
	}

	return 0;
}