#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string s;
	std::cin >> s;

	std::string t;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			t.push_back(s[i]);
		}
	}

	std::sort(t.begin(), t.end(), std::greater<char>());

	std::cout << t << "\n";

	return 0;
}