#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector<std::string> s(n);
	int m = 0;
	for (int i = 0; i < n; i++) {
		std::cin >> s[i];
		m = std::max(m, (int)s[i].size());
	}	

	for (int i = 0; i < n; i++) {
		int k = (m - s[i].size()) / 2;
		std::cout << std::string(k, '.') << s[i] << std::string(k, '.') << "\n";
	}

	return 0;
}