#include <bits/stdc++.h>

using namespace std;

const int N = 1010, M = 210, mod = 1e9 + 7;

int n, m, K;
char a[N], b[M];
int f[M][M], s[M][M];

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> K;

	cin >> a + 1 >> b + 1;

	f[0][0] = 1;
	for (int i = 1; i <= n; i ++ ) {
		for (int j = m; j >= 0; j -- ) {
			for (int k = K; k >= 0; k -- ) {
				if (a[i] == b[j]) {
					s[j][k] = (s[j - 1][k] + f[j - 1][k - 1]) % mod;
				} else {
					s[j][k] = 0;
				}
				f[j][k] = (f[j][k] + s[j][k]) % mod;
			}
		}
	}

	cout << f[m][K] << "\n";

	return 0;
}