#include <bits/stdc++.h>

using i64 = long long;

using namespace std;

#define int long long

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i ++ ) {
		cin >> a[i];
	}
	vector<int> b(n + 1);
	auto check = [&](int x) -> bool {
		if (x == 0) {
			return true;
		}
		for (int i = 0; i < n; i ++ ) {
			b[i] = (x + a[i] - 1) / a[i];
		}
		int cnt = 0;
		for (int i = 0; i < n; i ++ ) {
			if (b[i] <= 0) {
				if (i != n - 1) {
					cnt ++ ;
				}
			} else {
				cnt += b[i] * 2 - 1;
				b[i + 1] -= b[i] - 1;
			}
		}
		return cnt <= m;
	};
	int l = 0, r = 1e13;
	while (l < r) {
		int mid = l + r + 1 >> 1;
		if (check(mid)) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	cout << l << endl;
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