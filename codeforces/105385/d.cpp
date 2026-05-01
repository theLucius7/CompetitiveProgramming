#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i64 = long long;

using real = long double;

void solve() {
	int p, a, b, q, c, d, m, t;
	cin >> p >> a >> b >> q >> c >> d >> m >> t;
	auto get = [&]() -> int {
		int l = 0, r = m / p;
		while (l < r) {
			int mid = l + r + 1 >> 1;
			if (a * mid + b + c * mid + d <= t) {
				l = mid;
			} else {
				r = mid - 1;
			}
		}
		return m + l * (q - p);
	};
	if (m < p) {
		cout << m << endl;
		return;
	}
	while (true) {
		int x = m / p;
		int s = a * x + b + c * x + d;
		if (s > t) {
			cout << get() << endl;
			return;
		}
		int y = (p - m % p) / ((q - p) * x);
		if (y == 0) {
			y = 1;
		}
		if (y * s > t) {
			m += t / s * (q - p) * x;
			t -= t / s * s;
			cout << get() << endl;
			return;
		}
		m += y * (q - p) * x;
		t -= y * s;
		// cout << m << " " << t << " " << x << " " << y << endl;
	}
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