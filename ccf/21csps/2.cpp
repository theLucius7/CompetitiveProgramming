#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 510, mod = 1e9 + 7;

int n, k;
char s[N];
LL f[N][N][5];

bool check (int l, int r) {
	return (s[l] == '(' || s[l] == '?') && (s[r] == ')' || s[r] == '?');
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;

	cin >> s + 1;

	for (int i = 1; i <= n; i ++ ) {
		f[i][i - 1][2] = 1;
	}

	for (int len = 1; len <= n; len ++ ) {
		for (int l = 1; l + len - 1 <= n; l ++ ) {
			int r = l + len - 1;
			f[l][r][2] = f[l][r - 1][2] & (s[r] == '*' || s[r] == '?') & (len <= k);
			if (len > 1) {
				f[l][r][0] = (f[l + 1][r - 1][0] + f[l + 1][r - 1][1] + f[l + 1][r - 1][2] + f[l + 1][r - 1][3] + f[l + 1][r - 1][4]) * check (l, r) % mod;
				for (int k = l; k < r; k ++ ) {
					f[l][r][1] = (f[l][r][1] + (f[l][k][0] + f[l][k][1] + f[l][k][3]) * f[k + 1][r][0]) % mod;
					f[l][r][3] = (f[l][r][3] + (f[l][k][0] + f[l][k][1]) * f[k + 1][r][2]) % mod;
					f[l][r][4] = (f[l][r][4] + f[l][k][2] * (f[k + 1][r][0] + f[k + 1][r][1])) % mod;
				}
			}
		}
	}

	cout << (f[1][n][0] + f[1][n][1]) % mod << "\n";

	return 0;
}