#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	std::string s;
	std::cin >> s;

	int x = 0;
	int cnt = 0;
	for (int i = s.size() - 1; i >= 0; i--) {
		if (s[i] != '0') {
			x = i;
			break;
		}
		cnt++;
	}

	for (int i = 0; i < x; i++) {
		if (s[i] != '0') {
			cnt++;
		}
	}

	std::cout << cnt << "\n";
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