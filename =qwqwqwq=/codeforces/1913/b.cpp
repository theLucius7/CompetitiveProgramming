#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	std::string s;
	std::cin >> s;

	std::vector<int> cnt(2);
	cnt[0] = std::count(s.begin(), s.end(), '0'), cnt[1] = std::count(s.begin(), s.end(), '1');
	for (int i = 0; i < s.size(); i++) {
		if (cnt[1 - (s[i] - '0')] == 0) {
			std::cout << s.size() - i << "\n";
			return;
		}
		cnt[1 - (s[i] - '0')]--;
	}
	std::cout << 0 << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while(t--) {
		solve();
	}

	return 0;
}