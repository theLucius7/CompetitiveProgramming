#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	
	while (t -- ) {
		int n, m;
		cin >> n >> m;
		
		if (n < m) swap (n, m);

		int res = 0;
		
		if (n >= 3 && m == 1) {
			res = -1;
			cout << res << "\n";
			continue;
		}
		
		if ((n - m) % 2 == 0) res = 2 * n - 2;
		else res = 2 * n - 3;
		
		cout << res << "\n";
	}
	
	return 0;	
}