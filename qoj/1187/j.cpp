#include <bits/stdc++.h>

using i64 = long long;

using namespace std;

#define int long long

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i ++ ) {
		cin >> a[i];
	}
	if (n == m) {
		cout << "Richman\n";
		return;
	}
	// sort(a.begin() + 1, a.end());
	int cnt = count(a.begin() + 1, a.end(), 0ll);
	if (cnt > m) {
		cout << "Impossible\n";
		return;
	}
	int s = 0;
	// if (m == 0) {
	// 	s += *min_element(a.begin() + 1, a.end()) - 1;
	// }
	for (int i = 1, j = 0; i <= n, j <= m - cnt; i ++ ) {
		if (a[i]) {
			if (j == m - cnt) {
				int t = 1e9;
				for (int k = i; k <= n; k ++ ) {
					if (a[k]) {
						t = min(t, a[k]);
					}
				}
				s += t - 1;
				break;
			}
			s += a[i];
			j ++ ;
		}
	}
	cout << s << endl;
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