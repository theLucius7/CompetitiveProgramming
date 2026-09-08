#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;

	vector <string> s(n);
	for (int i = 0; i < n; i ++ ) cin >> s[i];
	
	int cnt[110][11];
	int st[11][110];
	memset (cnt, 0, sizeof cnt);
	memset (st, 0, sizeof st);
	
	for (int i = 0; i < n; i ++ ) {
		for (int j = 0; j < s[i].size (); j ++ ) {
			int x = s[i][j] - '0';
			cnt[i][x] = j;
			st[x][j] ++ ;
		}
	}
	
	int f[10], res = 0x3f3f3f3f3f;
	memset (f, 0, sizeof f);
	for (int i = 0; i < 10; i ++ ) {
		for (int j = 0; j < n; j ++ ) {
			f[i] = max ({f[i], cnt[j][i] + (st[i][cnt[j][i]] - 1) * 10});
		}
		res = min (res, f[i]);
	}
	
	cout << res << "\n";
	
	return 0;
}