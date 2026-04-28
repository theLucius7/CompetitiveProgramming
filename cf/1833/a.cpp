#include <bits/stdc++.h>

void solve() {
	int n;
	std::string s;
	std::cin >> n >> s;

	std::set<std::pair<int, int>> a;
	for (int i = 0; i < s.size() - 1; i++) {
		a.emplace(s[i], s[i + 1]);
	}

	std::cout << a.size() << "\n";
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