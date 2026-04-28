#include <bits/stdc++.h>

using i64 = long long;

std::string deal(char c, int n) {
	std::string s;
	for (int i = 0; i < n; i++) {
		s += c;
	}
	return s;
}

void solve() {
	std::string s;
	std::cin >> s;

	int cnt[26] = {0};
	for (char c : s) {
		cnt[c - 'A']++;
	}

	std::string ans = deal('T', cnt['T' - 'A']) + deal('N', cnt['N' - 'A']) + deal('F', cnt['F' - 'A']);

	for (char c = 'A'; c <= 'Z'; c++) {
		if (c != 'T' && c != 'N' && c != 'F') {
			ans = ans + deal(c, cnt[c - 'A']);
		}
	}

	std::cout << ans << "\n";
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