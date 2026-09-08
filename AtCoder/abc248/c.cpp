#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 2510, mod = 998244353;

int n, m, V;
int f[55][N];

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> V >> m;
	
	f[0][0] = 1;
	for (int i = 1; i <= n; i ++ ) {
		for (int v = 1; v <= V; v ++ ) {
			for (int j = v; j <= m; j ++ ) {
				f[i][j] = (f[i][j] + f[i - 1][j - v]) % mod;
			}
		}
	}
	
	int res = 0;
	for (int i = 1; i <= m; i ++ ) res = (res + f[n][i]) % mod;
	
	cout << res << "\n";
	
	return 0;
}