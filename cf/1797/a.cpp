#include <bits/stdc++.h>

using i64 = long long;

void solve () {
	int n, m;
	std::cin >> n >> m;

	int x1, y1, x2, y2;
	std::cin >> x1 >> y1 >> x2 >> y2;

	int ans = std::min ((x1 != 1) + (x1 != n) + (y1 != 1) + (y1 != m), (x2 != 1) + (x2 != n) + (y2 != 1) + (y2 != m));
	std::cout << ans << "\n";
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