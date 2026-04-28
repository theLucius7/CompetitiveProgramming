#include <bits/stdc++.h>

using i64 = long long;

void solve () {
	int n;
	std::cin >> n;

	std::string s;
	std::cin >> s;

	int i = 0, j = n;
	while (i + 2 <= j && s[i] != s[j - 1]) {
		i ++ , j -- ;
	}
	std::cout << j - i << "\n";
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