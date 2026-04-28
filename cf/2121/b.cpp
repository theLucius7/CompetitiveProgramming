#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1E8 + 1;

void solve() {
	int n;
	std::cin >> n;

	std::string s;
	std::cin >> s;

	std::vector<int> cnt(26);
	for (int i = 0; i < s.size(); i++) {
		cnt[s[i] - 'a']++;
	}

	for (int i = 1; i < s.size() - 1; i++) {
		if (cnt[s[i] - 'a'] > 1) {
			std::cout << "YES\n";
			return;
		}
	}
	std::cout << "NO\n";
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