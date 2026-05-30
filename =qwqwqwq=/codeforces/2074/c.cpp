#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int x;
	std::cin >> x;

	int p0 = -1, p1 = -1, cnt = 0;
	std::string s;
	while (x) {
		s += (char)('0' + x % 2);
		x /= 2;
	}
	std::reverse(s.begin(), s.end());
	// std::cout << s << "\n";

	for (int i = s.size() - 1; i >= 0; i--) {
		if (s[i] == '0') {
			p0 = i;
			break;
		}
	}
	for (int i = s.size() - 1; i >= 0; i--) {
		if (s[i] == '1') {
			p1 = i;
			cnt++;
		}
	}

	if (p0 == -1 || p1 == -1 || cnt == 1) {
		std::cout << "-1\n";
	} else {
		std::swap(s[p0], s[p1]);

		int b = 1, y = 0;
		for (int i = s.size() - 1; i >= 0; i--) {
			y += (s[i] == '1') * b;
			b *= 2;
		}
		std::cout << y << "\n";
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