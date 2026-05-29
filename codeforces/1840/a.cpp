#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;

	std::string s;
	std::cin >> s;

	for (int i = 0; i < n; i++) {
		std::cout << s[i];
		i = s.find(s[i], i + 1);
	}
	std::cout << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}