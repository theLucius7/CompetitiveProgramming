#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::string s;
	while (n) {
		s += char('0' + n % 2);
		n /= 2;
	}
	
	for (int i = s.size(); i < 32; i++) {
		s += '0';
	}

	std::reverse(s.begin(), s.end());

	// std::cout << s << "\n";

	std::vector<int> t(32);
	for (int i = 0; i < 32; i++) {
		t[i] = s[i] - '0';
	}

	// std::cout << s << "\n";

	if (t[31] == 0 && t[30] == 0) {
		std::cout << "NO\n";
		return;
	}

	for (int i = 0; i < t.size(); i++) {
		if (t[i] == 0) {
			t[i] = 1;

			for (int j = i + 1; j < t.size(); j++) {
				bool ok = false;
				if (t[j] == 1) {
					ok = true;
				}

				t[j] = -1;

				if (ok) {
					i = j;
					break;
				}
			}
		}
	}
	
	std::cout << "YES\n";
	for (int i = 0; i < 32; i++) {
		std::cout << t[i] << " \n"[i % 8 == 7];
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

