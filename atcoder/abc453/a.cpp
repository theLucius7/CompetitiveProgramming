#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::string S;
	std::cin >> S;

	for (int i = 0; i < N; i++) {
		if (S[i] != 'o') {
			for (int j = i; j < N; j++) {
				std::cout << S[j];
			}
			return 0;
		}
	}

	return 0;
}	