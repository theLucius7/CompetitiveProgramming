#include <bits/stdc++.h>

using namespace std;

const int N = 310;

typedef long long i64;

void solve () {
	string s;
	cin >> s;
	
	int x = 110, y = 110;
	
	int n = s.size ();
	
	int g[N][N];
	memset (g, true, sizeof g);
	
	for (int i = 0; i < n; i ++ ) {
		if (s[i] == 'L') {
			g[x + 1][y] = g[x - 1][y] = g[x][y + 1] = false;
			y -- ;
			if (!g[x][y]) {
				cout << "BUG\n";
				return;
			}
			g[x][y] = false;
		} else if (s[i] == 'R') {
			g[x + 1][y] = g[x - 1][y] = g[x][y - 1] = false;
			y ++ ;
			if (!g[x][y]) {
				cout << "BUG\n";
				return;
			}
			g[x][y] = false;
		} else if (s[i] == 'U') {
			g[x + 1][y] = g[x][y + 1] = g[x][y - 1] = false;
			x -- ;
			if (!g[x][y]) {
				cout << "BUG\n";
				return;
			}
			g[x][y] = false;
		} else {
			g[x - 1][y] = g[x][y + 1] = g[x][y - 1] = false;
			x ++ ;
			if (!g[x][y]) {
				cout << "BUG\n";
				return;
			}
			g[x][y] = false;
		}
	}
	
	cout << "OK\n";
		
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();
	
	return 0;
}