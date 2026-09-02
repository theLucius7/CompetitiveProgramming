#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string S;
	std::cin >> S;

	for (int i = 0; i < S.size(); i++) {
		if (S[i] >= 'A' && S[i] <= 'Z') {
			std::cout << S[i];
		}
	}

	return 0;
}