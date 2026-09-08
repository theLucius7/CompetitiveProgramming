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
		
		int cnt[3] {};
		for (int i = 0; i < n; i ++ ) {
			for (int j = 0; j < n; j ++ ) {
				if (s[i][j] == 'X') cnt[(i + j) % 3] ++ ;
			}
		}
		
		int x = 0;
		for (int i = 1; i < 3; i ++ ) {
			if (cnt[i] < cnt[x]) {
				x = i;
			}
		}
		
		for (int i = 0; i < n; i ++ ) {
			for (int j = 0; j < n; j ++ ) {
				if (s[i][j] == 'X' && (i + j) % 3 == x) {
					s[i][j] = 'O';
				}
			}
			cout << s[i] << "\n";
		}
	}
	
	return 0;
}