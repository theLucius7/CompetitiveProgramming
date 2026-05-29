#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::string s;
	std::cin >> s;

	for (int i = 0; i < n; i++) {
		std::cout << s[i] << s[i];
	}
	std::cout << "\n";

	return 0;
}