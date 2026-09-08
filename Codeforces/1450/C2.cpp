#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	
	while (t -- ) {
		int n;
		cin >> n;
		
		vector <string> s(n);
		for (int i = 0; i < n; i ++ ) {
			cin >> s[i];
		}
		
		int cnt[2][3] {};
		for (int i = 0; i < n; i ++ ) {
			for (int j = 0; j < n; j ++ ) {
				if (s[i][j] == 'X') cnt[1][(i + j) % 3] ++ ;
				if (s[i][j] == 'O') cnt[0][(i + j) % 3] ++ ;
			}
		}
		
		int x = 0;
		for (int i = 1; i < 3; i ++ ) {
			if (cnt[0][(i + 1) % 3] + cnt[1][(i + 2) % 3] < cnt[0][(x + 1) % 3] + cnt[1][(x + 2) % 3]) {
				x = i;
			}
		}
		
		for (int i = 0; i < n; i ++ ) {
			for (int j = 0; j < n; j ++ ) {
				if (s[i][j] == 'O' && (i + j) % 3 == (x + 1) % 3) {
					s[i][j] = 'X';
				}
				if (s[i][j] == 'X' && (i + j) % 3 == (x + 2) % 3) {
					s[i][j] = 'O';
				}
			}
			cout << s[i] << "\n";
		}
	}
	
	return 0;
}