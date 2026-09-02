#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::string S, T;
	std::cin >> S >> T;

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt += (S[i] != T[i]);
	}
	std::cout << cnt << "\n";

	return 0;
}