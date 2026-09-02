#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	i64 N;
	int M;
	std::cin >> N >> M;

	std::vector<std::tuple<i64, i64, i64>> P(M);
	for (int i = 0; i < M; i++) {
		i64 A, B;
		std::cin >> A >> B;
		P[i] = {A - B, A, B};
	}

	std::sort(P.begin(), P.end());

	i64 ans = 0;
	for (auto [D, A, B] : P) {
		if (N >= A) {
			i64 x = std::max(0ll, (N - A) / D + 1ll);
			N -= x * D;
			ans += x;
		}
	}
	std::cout << ans << "\n";

	return 0;
}