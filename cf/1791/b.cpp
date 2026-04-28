#include <bits/stdc++.h>

using i64 = long long;

void solve () {
	int n;
	std::cin >> n;
	
	std::string s;
	std::cin >> s;

	int x = 0, y = 0;
	for (auto c : s) {
		if (c == 'L') x -- ;
		else if (c == 'R') x ++ ;
		else if (c == 'U') y ++ ;
		else y -- ;

		if (x == 1 && y == 1) {
			std::cout << "YES\n";
			return;
		}
	}
	std::cout << "NO\n";
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