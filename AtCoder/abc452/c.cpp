#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::vector<std::pair<int, int>> v(N);
	for (int i = 0; i < N; i++) {
		std::cin >> v[i].first >> v[i].second;
	}

	int M;
	std::cin >> M;

	std::vector<std::string> S(M);
	std::map<char, bool> has[N];
	for (int i = 0; i < M; i++) {
		std::cin >> S[i];
		for (int j = 0; j < N; j++) {
			if (S[i].size() == v[j].first) {
				has[j][S[i][v[j].second - 1]] = true;
			}
		}
	}

	for (int i = 0; i < M; i++) {
		if (S[i].size() != N) {
			std::cout << "No\n";
			continue;
		}

		bool ok = true;
		for (int j = 0; j < S[i].size(); j++) {
			if (!has[j][S[i][j]]) {
				ok = false;
				break;
			}
		}

		std::cout << (ok ? "Yes" : "No") << "\n";
	}

	return 0;
}	