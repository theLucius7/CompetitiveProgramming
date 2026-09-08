#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	
	vector <string> s1(n);
	for (int i = 0; i < n; i ++ ) {
		cin >> s1[i];
	}
	
	vector <string> s2(n);
	for (int i = 0; i < n; i ++ ) {
		cin >> s2[i];
	}
	
	int cnt = 0;
	for (int i = 0; i < n; i ++ ) {
		for (int j = 0; j < m; j ++ ) {
			if (s2[i][j] != s1[i][j] ) cnt ++ ;
		}
	}
	
	if (cnt > n * m / 2) {
		for (int i = 0; i < n; i ++ ) {
			for (int j = 0; j < m; j ++ ) {
				if (s1[i][j] == 'X') s1[i][j] = '.';
				else s1[i][j] = 'X';
			}
		}
	}
	
	for (int i = 0; i < n; i ++ ) cout << s1[i] << "\n";		
	
	return 0;
}