#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	
	while (t -- ) {
		int g[N];
		int st[N];
		memset (st, 0, sizeof st);
		
		int n;
		cin >> n;
		
		for (int i = 1; i <= n; i ++ ) {
			int x;
			cin >> x;
			st[x] ++ ;
		}
	
		bool res = false;
		
		for (int i = 1; i <= n; i ++ ) {
			if (st[i] >= 3) {
				res = true;
				cout << i << "\n";
				break;
			}
		}
		
		if (!res) cout << -1 << "\n";
	}
	
	return 0;
} //