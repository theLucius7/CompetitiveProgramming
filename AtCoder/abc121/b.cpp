#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, c;
	cin >> n >> m >> c;

	vector <int> b(m);
	for (int i = 0; i < m; i ++ ) {
		cin >> b[i];
	}

	int res = 0;
	vector <vector <int>> a(n, vector <int> (m));
	for (int i = 0; i < n; i ++ ) {
		int ans = c;
		for (int j = 0; j < m; j ++ ) {
			cin >> a[i][j];
			ans += a[i][j] * b[j];
		}
		if (ans > 0) {
			res ++ ;
		}
	}

	cout << res << "\n";

	return 0;
}