#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, L, R;
	std::cin >> n >> L >> R;

	std::string s;
	std::cin >> s;

	for (int i = L - 1; i < R; i++) {
		if (s[i] == 'x') {
			std::cout << "No\n";
			return 0;
		}
	}
	std::cout << "Yes\n";

	return 0;
}