#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string S, T;
	std::cin >> S >> T;

	for (int i = 1; i < S.size(); i++) {
		if (isupper(S[i])) {
			if (T.find(S[i - 1]) == T.npos) {
				std::cout << "No\n";
				return 0;
			}
		}
	}
	std::cout << "Yes\n";

	return 0;
}