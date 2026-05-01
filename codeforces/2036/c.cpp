#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	std::string s;
	std::cin >> s;

	int q;
	std::cin >> q;

	int cnt = 0;

	for (int i = 0; i + 3 < s.size(); i++) {
		if (s.substr(i, 4) == "1100") {
			cnt++;
		}
	}

	while (q--) {
		int i;
		char v;
		std::cin >> i >> v;
		i--;

		for (int l = std::max(0, i - 3); l <= i; l++) {
			if (l + 3 < s.size()) {
				cnt -= (s.substr(l, 4) == "1100");
			}
		}

		s[i] = v;

		for (int l = std::max(0, i - 3); l <= i; l++) {
			if (l + 3 < s.size()) {
				cnt += (s.substr(l, 4) == "1100");
			}
		}

		std::cout << (cnt != 0 ? "YES" : "NO") << "\n";
	}
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
