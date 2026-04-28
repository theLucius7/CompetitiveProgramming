#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, M;
	std::cin >> N >> M;

	std::vector<std::string> C(N);
	for (int i = 0; i < N; i++) {
		std::cin >> C[i];
	}

	std::unordered_map<std::string, int> D(M);
	for (int i = 0; i < M; i++) {
		std::string d;
		std::cin >> d;
		D[d] = i + 1;
	}

	std::vector<int> P(M + 1);
	for (int i = 0; i < M + 1; i++) {
		std::cin >> P[i];
	}

	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (D.find(C[i]) != D.end()) {
			ans += P[D[C[i]]];
		} else {
			ans += P[0];
		}
	}

	std::cout << ans << "\n";

	return 0;
}