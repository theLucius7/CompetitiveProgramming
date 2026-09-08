#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

typedef pair <int, int> PII;
typedef long long LL;

const int N = 5010;

int n, m;
int a[N];
LL s[N];
vector <PII> W;
LL f[N][N];
LL ans[N][N];

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (int i = 1; i <= n; i ++ ) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
		f[i][i] = a[i];
	}

	for (int i = 0; i < m; i ++ ) {
		int c, y;
		cin >> c >> y;
		int sz = W.size ();
		for (int j = 0; j < sz; j ++ ) {
			int c0 = W[j].fi, yx = W[j].se;
			W.push_back ({max (c0, c), yx + y});
		}
		W.push_back ({c, y});
	}

	for (auto w : W) {
		int c = w.fi, y = w.se;
		for (int i = 1; i + c <= n + 1; i ++ ) {
			f[i][i + c] = max (f[i][i + c], s[i + c] - s[i - 1] - min (a[i], a[i + c]) + y);
			if (i + c == n + 1) {
				f[i][n] = max (f[i][n], s[n] - s[i - 1] + y);
			}
		}
	}

	for (int len = 1; len <= n; len ++ ) {
		for (int i = 1; i + len - 1 <= n; i ++ ) {
			int j = i + len - 1;
			for (int k = i; k < j; k ++ ) {
				f[i][j] = max (f[i][j], f[i][k] + f[k + 1][j]);
			}
		}
	}
	
	cout << f[1][n] << "\n";

	return 0;
}