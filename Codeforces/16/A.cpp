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

	for (int i = 0; i < n; i ++ ) {
		if (i && s[i][0] == s[i - 1][0]) {
			cout << "NO\n";
			return;
		}
		for (int j = 0; j < m; j ++ ) {
			if (j && s[i][j] != s[i][j - 1]) {
				cout << "NO\n";
				return;
			}
		}
	}

	cout << "YES\n";
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();
	
	return 0;
}