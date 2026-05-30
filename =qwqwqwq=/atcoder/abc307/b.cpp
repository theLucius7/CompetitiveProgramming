#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::vector<std::string> S(N);
	for (int i = 0; i < N; i++) {
		std::cin >> S[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i != j) {
				std::string t = S[i] + S[j];
				std::string T = t;
				std::reverse(t.begin(), t.end());
				if (t == T) {
					std::cout << "Yes\n";
					return 0;
				}
			}
		}
	}

	std::cout << "No\n";

	return 0;
}