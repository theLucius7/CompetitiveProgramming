#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, M;
	std::cin >> N >> M;

	std::vector<int> F(N);
	std::vector<int> cnt(M);
	for (int i = 0; i < N; i++) {
		std::cin >> F[i];
		F[i]--;
		cnt[F[i]]++;
	}


	bool ok1 = true, ok2 = true;
	for (int i = 0; i < M; i++) {
		if (cnt[i] > 1) {
			ok1 = false;
		}
		if (cnt[i] == 0) {
			ok2 = false;
		}
	}
	std::cout << (ok1 ? "Yes" : "No") << "\n";
	std::cout << (ok2 ? "Yes" : "No") << "\n";

	return 0;
}