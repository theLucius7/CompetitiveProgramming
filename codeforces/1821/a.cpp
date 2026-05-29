#include <bits/stdc++.h>

using i64 = long long;

void solve () {
	std::string s;
	std::cin >> s;

	if (s[0] == '0') {
		std::cout << 0 << "\n";
		return;
	}

	int ans = 0;
	if (s[0] == '?') {
		ans += 9;
	}
	for (int i = 1; i < s.size (); i ++ ) {
		if (s[i] == '?') {
			ans = std::max (1, ans);
			ans *= 10;
		}
	}
	std::cout << std::max (1, ans) << "\n";
}

int main () {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while (t -- ) {
		solve ();
	}

	return 0;
}