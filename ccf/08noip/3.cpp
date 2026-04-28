#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int n, m;
int g[N][N];
int f[2 * N][N][N];

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (int i = 1; i <= n; i ++ ) {
		for (int j = 1; j <= m; j ++ ) {
			cin >> g[i][j];
		}
	}

	for (int k = 2; k <= n + m; k ++ ) {
		for (int i1 = 1; i1 <= n && i1 < k; i1 ++ ) {
			for (int i2 = 1; i2 <= n && i2 < k; i2 ++ ) {
				int j1 = k - i1, j2 = k - i2;
				if (i1 != i2 || k == 2 || k == n + m) {
					int &x = f[k][i1][i2];
					int t = g[i1][j1] + g[i2][j2];

					x = max ({x, f[k - 1][i1 - 1][i2] + t, f[k - 1][i1 - 1][i2 - 1] + t, f[k - 1][i1][i2 - 1] + t, f[k - 1][i1][i2] + t});
				}
			}
		}
	}

	cout << f[n + m][n][n] << "\n";

	return 0;
}