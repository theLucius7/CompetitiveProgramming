#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve () {
	int n, m;
	cin >> n >> m;

	vector <string> s(n);
	for (int i = 0; i < n; i ++ ) {
		cin >> s[i];
	}

	int minx = n, maxx = -1, miny = m, maxy = -1;
	for (int i = 0; i < n; i ++ ) {
		for (int j = 0; j < m; j ++ ) {
			if (s[i][j] == '*') {
				minx = min (minx, i);
				maxx = max (maxx, i);
				miny = min (miny, j);
				maxy = max (maxy, j);
			}
		}
	}

	for (int i = minx; i <= maxx; i ++ ) {
		for (int j = miny; j <= maxy; j ++ ) {
			cout << s[i][j];
		}
		cout << "\n";
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();
	
	return 0;
}