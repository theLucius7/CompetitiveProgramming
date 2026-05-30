#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::vector<std::string> S(N);
	for (int i = 0; i < N; i++) {
		std::cin >> S[i];
	}

	std::vector<char> d(2 * N, '?');
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (d[i + j] == '?' && S[i][j] != '?') {
				d[i + j] = S[i][j];
			}
		}
	}

	for (int i = 0; i <= 2 * N - 2; i++) {
		if (d[i] == '?') {
			d[i] = '0';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (S[i][j] == '?') {
				S[i][j] = d[i + j];
			} else if (S[i][j] != d[i + j]) {
				std::cout << "-1\n";
				return 0;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		std::cout << S[i] << "\n";
	}


	return 0;
}