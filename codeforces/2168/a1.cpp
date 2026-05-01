#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string t;
	std::cin >> t;

	if (t == "first") {
		int n;
		std::cin >> n;

		std::vector<int> a(n);
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
		}

		for (int i = 0; i < n; i++) {
			std::cout << char(a[i] + 'a' - 1);
		}
		std::cout << "\n";
	} else {
		std::string s;
		std::cin >> s;

		std::cout << s.size() << "\n";
		for (int i = 0; i < s.size(); i++) {
			std::cout << s[i] - 'a' + 1 << " \n"[i == s.size() - 1];
		}
	}
	

	return 0;
}