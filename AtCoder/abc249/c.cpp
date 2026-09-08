#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, k;
	cin >> n >> k;
	
	vector <string> s(n);
	for (int i = 0; i < n; i ++ ) cin >> s[i];
	
	int res = 0;
	for (int i = 0; i < (1 << n); i ++ ) {
		vector <int> sum (26);
		
		for (int j = 0; j < n; j ++ ) {
			if ((i >> j) & 1) {
				for (int k = 0; k < s[j].size (); k ++ ) {
					sum[s[j][k] - 'a'] ++ ;
				}
				
			}
		}
		
		int ans = 0;
		for (int i = 0; i < 26; i ++ ) {
			if (sum[i] == k) ans ++ ;
		}
		
		res = max (res, ans);
	}
	
	cout << res << "\n";
	
	return 0;
}