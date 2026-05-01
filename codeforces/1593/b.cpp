#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	std::string n;
	std::cin >> n;

	std::vector<bool> ok(2);
	for (int i = n.size() - 1; i >= 0; i--) {
		if (ok[0] && (n[i] == '0' || n[i] == '5')) {
			std::cout << n.size() - 2 - i << "\n";
			return;
		}
		if (ok[1] && (n[i] == '2' || n[i] == '7')) {
			std::cout << n.size() - 2 - i << "\n";
			return;
		}
		if (n[i] == '0') {
			ok[0] = true;
		}
		if (n[i] == '5') {
			ok[1] = true;
		}
	}
	std::cout << n.size() << "\n";
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