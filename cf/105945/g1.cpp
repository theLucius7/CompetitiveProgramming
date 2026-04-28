#include <bits/stdc++.h>
#define int long long
using namespace std;
using i64 = long long;


void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (int i = 0; i < n; i ++ ) {
		cin >> a[i];
	}
	auto check = [&](int x) -> bool {
		int ans = n;
		for (int i = 0; i + 1 < n; i ++ ) {
			int l = 0, r = i;
			while (l < r) {
				int mid = l + r + 1 >> 1;
				if (a[i] + (x - 1) * a[mid] < a[i + 1]) {
					l = mid;
				} else {
					r = mid - 1;
				}
			}
			if (a[i] + (x - 1) * a[l] < a[i + 1]) {
				ans += l + 1;
			}
		}
		cout << ans << endl;
		return ans == a.back();
	};
	cout << check(2) << endl;
	int l = 1, r = 1e9;
	// while (l < r) {
	// 	int mid = l + r >> 1;
	// 	if (check(mid)) {
	// 		r = mid;
	// 	} else {
	// 		l = mid + 1;
	// 	}
	// }
	// cout << l << endl;
	for (int j = 0; j < q; j ++ ) {
		int m;
		cin >> m;
		int ans = n;
		if (m >= l) {
			ans = a.back();
		} else {
			for (int i = 0; i + 1 < n; i ++ ) {
				int L = 0, R = i;
				while (L < R) {
					int mid = L + R + 1 >> 1;
					if (a[i] + (m - 1) * a[mid] < a[i + 1]) {
						L = mid;
					} else {
						R = mid - 1;
					}
				}
				if (a[i] + (m - 1) * a[L] < a[i + 1]) {
					ans += L + 1;
				}
			}
		}
		cout << ans << " \n"[j == q - 1];
	}
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	// std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}