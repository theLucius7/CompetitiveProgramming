#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::string S;
	std::cin >> S;

	std::cout << std::string(N - S.size(), 'o') + S << "\n";
	

	return 0;
}

