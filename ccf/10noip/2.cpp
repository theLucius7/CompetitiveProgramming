#include <bits/stdc++.h>

using namespace std;

const int N = 360, M = 45;

int n, m;
int w[N];
int f[M][M][M][M];
int cnt[5];

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (int i = 1; i <= n; i ++ ) {
		cin >> w[i];
	}

	for (int i = 0; i < m; i ++ ) {
		int x;
		cin >> x;

		cnt[x] ++ ;
	}

	f[0][0][0][0] = w[1];
	for (int a = 0; a <= cnt[1]; a ++ ) {
		for (int b = 0; b <= cnt[2]; b ++ ) {
			for (int c = 0; c <= cnt[3]; c ++ ) {
				for (int d = 0; d <= cnt[4]; d ++ ) {
					int s = a * 1 + b * 2 + c * 3 + d * 4 + 1;
					if (a != 0) {
						f[a][b][c][d] = max (f[a][b][c][d], f[a - 1][b][c][d] + w[s]);
					}
					if (b != 0) {
						f[a][b][c][d] = max (f[a][b][c][d], f[a][b - 1][c][d] + w[s]);
					}
					if (c != 0) {
						f[a][b][c][d] = max (f[a][b][c][d], f[a][b][c - 1][d] + w[s]);
					}
					if (d != 0) {
						f[a][b][c][d] = max (f[a][b][c][d], f[a][b][c][d - 1] + w[s]);
					}
				}
			}
		}
	}

	cout << f[cnt[1]][cnt[2]][cnt[3]][cnt[4]] << "\n";

	return 0;
}