#include <bits/stdc++.h>

using i64 = long long;

void solve () {
	std::string s;
	std::cin >> s;

	if (s == "^") {
		std::cout << 1 << "\n";
		return;
	}

	int cnt = 0;
	for (int i = 0; i < s.size (); i ++ ) {
		if (s[i] == '_') {
			if (!i || s[i - 1] == '_') {
				cnt ++ ;
			}
			if (i == s.size () - 1) {
				cnt ++ ;
			}
		}
	}

	std::cout << cnt << "\n";
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