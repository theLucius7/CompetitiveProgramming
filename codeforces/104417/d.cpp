#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
using i64 = long long;
using i128 = __int128;
using real = long double;

void solve() {
	int n, k, m, a, b;
	cin >> n >> k >> m >> a >> b;
	if (k == 1) {
		if (n % m == 0) {
			cout << "0\n";
		} else {
			cout << "-1\n";
		}
		return;
	}
	int ans = LLONG_MAX;
	// i128 q = 1;
	int p = 0;
	for (int i = 0; n >= 1; i ++ , n /= k, p ++ ) {
		i128 q = 1;
		int cnt = 0;
		while (true) {
			i128 x = (n * q + m - 1) / m * m;
			if (x - n * q < q) {
				ans = min(ans, i * b + cnt * a);
				break;
			}
			q *= k;
			cnt ++ ;
		}
	}
	cout << min(ans, p * b) << endl;
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int T = 1;
	cin >> T;
	while (T -- ) {
		solve();
	}

	return 0;
}