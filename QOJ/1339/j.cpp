#include <bits/stdc++.h>

using i64 = long long;

using namespace std;

#define int long long

void solve() {
	int a, b, c, d, v, t;
	cin >> a >> b >> c >> d >> v >> t;
	int ans = 0;
	for (int i = 1, j = 0; i <= c; i ++ ) {
		int x = (i * a + c - 1) / c;
		int y = (i * a + v) / c;
		x = max(x, j + 1);
		y = min(y, t / c);
		ans += max(0ll, y - x + 1);
		j = max(j, y);
	}
	for (int i = 1, j = 0; i <= a; i ++ ) {
		int x = (i * c + a - 1) / a;
		int y = (i * c + v) / a;
		x = max(x, j + 1);
		y = min(y, t / a);
		ans += max(0ll, y - x + 1);
		j = max(j, y);
	}
	int p = a * c / __gcd(a, c);
	
	cout << ans << endl;
	ans += (t / a + 1) * (b - 1);
	ans += (t / c + 1) * (d - 1);
	// ans += (t / p + 1);
	cout << ans << endl;
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}


	return 0;
}