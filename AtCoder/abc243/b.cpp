#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector <vector <int>> a(2, vector <int>(n, 0));
	for (int i = 0; i < 2; i ++ ) {
		for (int j = 0; j < n; j ++ ) {
			cin >> a[i][j];
		}
	}

	int res = 0, ans = 0;
	vector <bool> st(1e9 + 10);
	for (int i = 0; i < 2; i ++ ) {
		for (int j = 0; j < n; j ++ ) {
			if (i == 0) {
				st[a[i][j]] = true;
			} else {
				if (a[i][j] == a[i - 1][j]) res ++ ;
				else if (st[a[i][j]]) ans ++ ;
			}
		}
	}

	cout << res << "\n" << ans << "\n";

	return 0;
}