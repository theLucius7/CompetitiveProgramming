#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, M;
	std::cin >> N >> M;

	std::vector<std::string> S(N);
	for (int i = 0; i < N; i++) {
		std::cin >> S[i];
	}

	std::set<std::vector<std::string>> set;
	for (int i = 0; i + M - 1 < N; i++) {
		for (int j = 0; j + M - 1 < N; j++) {
			std::vector<std::string> s;
			for (int k = 0; k < M; k++) {
				s.push_back(S[i + k].substr(j, M));
			}
			set.insert(s);
		}
	}
	std::cout << set.size() << "\n";

	return 0;
}