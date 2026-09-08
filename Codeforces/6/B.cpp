#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

int dx[4] = {0, -1, 0, 1}, dy[4] = {1, 0, -1, 0};

void solve () {
	int n, m;
	cin >> n >> m;

	char c;
	cin >> c;

	vector <string> s(n);
	for (int i = 0; i < n; i ++ ) {
		cin >> s[i];
	}

	set <char> set;
	for (int i = 0; i < n; i ++ ) {
		for (int j = 0; j < m; j ++ ) {
			if (s[i][j] == c) {
				for (int k = 0; k < 4; k ++ ) {
					int a = i + dx[k], b = j + dy[k];
					if (a >= 0 && a < n && b >= 0 && b < m && s[a][b] != c && s[a][b] != '.') {
						set.insert (s[a][b]);
					} 
				}
			}
		}
	}

	cout << set.size () << "\n";
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();
	
	return 0;
}