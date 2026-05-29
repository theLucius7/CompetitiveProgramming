#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	if (N < 3) {
		std::cout << "No\n";
		return 0;
	}

	std::string S;
	std::cin >> S;

	std::cout << ((S.substr(N - 3, 3) == "tea") ? "Yes" : "No") << "\n";

	return 0;
}