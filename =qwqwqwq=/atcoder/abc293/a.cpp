#include <bits/stdc++.h>

using i64 = long long;

int main () {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string S;
	std::cin >> S;

	for (int i = 0; i < S.size (); i += 2) {
		std::swap (S[i], S[i + 1]);
	}

	std::cout << S << "\n";

	return 0;
}