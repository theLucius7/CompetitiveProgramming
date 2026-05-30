#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, M;
	std::cin >> N >> M;

	std::string S, T;
	std::cin >> S >> T;

	std::vector<std::vector<bool>> used(2, std::vector<bool>(26));
	for (int i = 0; i < S.size(); i++) {
		used[0][S[i] - 'a'] = true;
	}
	for (int i = 0; i < T.size(); i++) {
		used[1][T[i] - 'a'] = true;
	}

	int Q;
	std::cin >> Q;

	while (Q--) {
		std::string w;
		std::cin >> w;

		bool ok1 = true, ok2 = true;;
		for (int i = 0; i < w.size(); i++) {
			if (!used[0][w[i] - 'a']) {
				ok1 = false;
				break;
			}
		}
		for (int i = 0; i < w.size(); i++) {
			if (!used[1][w[i] - 'a']) {
				ok2 = false;
				break;
			}
		}

		if (ok1 == ok2) {
			std::cout << "Unknown\n";
		} else if (ok1) {
			std::cout << "Takahashi\n";
		} else {
			std::cout << "Aoki\n";
		}

	}


	return 0;
}