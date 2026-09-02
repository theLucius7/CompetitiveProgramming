#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string S;
	std::cin >> S;

	std::cout << (S.front() == S.back() ? "Yes" : "No") << "\n";
	

	return 0;
}