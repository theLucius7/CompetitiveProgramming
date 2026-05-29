#include <bits/stdc++.h>

using i64 = long long;

#define int long long

constexpr int P = 998244353;

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string S;
	std::cin >> S;

	for (int i = 0; i < S.size(); i++) {
		if (S[i] == 'S') {
			S[i] = 'N';
		} else if (S[i] == 'N') {
			S[i] = 'S';
		} else if (S[i] == 'W') {
			S[i] = 'E';
		} else {
			S[i] = 'W';
		}
	}

	std::cout << S << "\n";

	return 0;
}