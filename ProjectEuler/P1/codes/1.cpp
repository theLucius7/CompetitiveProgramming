#include <bits/stdc++.h>

using i64 = long long;

int n = 1000;

void solve () {
	int res = 0;

	for (int i = 1; i < n; i ++ ) {
		if (i % 3 == 0 || i % 5 == 0) {
			res += i;
		}
	}

	std::cout << res << "\n";
}

int main () {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve ();

	return 0;
}