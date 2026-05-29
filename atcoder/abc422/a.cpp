#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string S;
	std::cin >> S;

	if (S[0] == '8' && S[2] == '8') {
		std::cout << S << "\n";
	} else if (S[2] == '8') {
		std::cout << char(S[0] + 1) << S[1] << 1 << "\n";
	} else {
		std::cout << S[0] << S[1] << char(S[2] + 1) << "\n";
	}

	return 0;
}