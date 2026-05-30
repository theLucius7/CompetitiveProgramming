#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string s;
	std::cin >> s;

	std::vector<std::pair<int, int>> v;
	for (int l = 0; l < s.size(); ) {
		int r = l + 1;
		while (r < s.size() && s[l] == s[r]) {
			r++;
		}
		v.emplace_back(s[l] - '0', r - l);
		l = r;
	}

	int ans = 0;
	for (int i = 1; i < v.size(); i++) {
		if (v[i].first == v[i - 1].first + 1) {
			ans += std::min(v[i].second, v[i - 1].second);
		}
	}
	std::cout << ans << "\n";

	return 0;
}