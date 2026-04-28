#include <bits/stdc++.h>

using i64 = long long;

bool isGood(int n) {
	std::string s = std::to_string(n);
	for (int i = s.size() - 1; i >= 0; i--) {
		if ((s.size() - i) & 1) {
			if (!((s[i] - '0') & 1)) {
				return false;
			}
		} else {
			if ((s[i] - '0') & 1) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += isGood(i);
	}

	std::cout << ans << "\n";

	return 0;
}