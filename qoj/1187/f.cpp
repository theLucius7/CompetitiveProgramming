#include <bits/stdc++.h>

using i64 = long long;

using namespace std;

#define int long long

void solve() {
	int n, k;
	cin >> n >> k;
	if ((n & 1) || k < n / 2 || k > n - 1) {
		cout << "Impossible\n";
		return;
	}
	vector<vector<int>> a(k + 1, vector<int>(n + 1));
	for (int i = 1; i <= n / 2; i ++ ) {
		if (i != 1) {
			for (int j = 1; j <= n - 2; j += 2) {
				a[i][j] = a[i - 1][j + 3];
				a[i][j + 1] = a[i - 1][j + 2];
			}
			a[i][n - 1] = a[i - 1][2];
			a[i][n] = a[i - 1][1];
		} else {
			for (int j = 1; j <= n; j ++ ) {
				if (j & 1) {
					a[i][j] = j + 1;
				} else {
					a[i][j] = j - 1;
				}
			}
		}
	}
	for (int i = n / 2 + 1; i <= k; i ++ ) {
		for (int j = 1; j <= n; j += 2) {
			a[i][j] = a[i - n / 2 + 1][j + 1];
			a[i][j + 1] = a[i - n / 2 + 1][j];
		}
	}
	for (int i = 1; i <= n / 2; i ++ ) {
		if (i != 1 && i + n / 2 - 1 <= k && (i & 1)) {
			for (int j = 1; j <= n; j ++ ) {
				cout << a[i + n / 2 - 1][j] << " \n"[j == n];
			}
		}
		for (int j = 1; j <= n; j ++ ) {
			cout << a[i][j] << " \n"[j == n];
		}
		if (i != 1 && i + n / 2 - 1 <= k && !(i & 1)) {
			for (int j = 1; j <= n; j ++ ) {
				cout << a[i + n / 2 - 1][j] << " \n"[j == n];
			}
		}
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