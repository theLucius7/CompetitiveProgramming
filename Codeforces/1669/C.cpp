#include <bits/stdc++.h>

using namespace std;

const int N = 52;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	
	while (t -- ) {
		int n;
		int a[N];
		
		cin >> n;
		for (int i = 1; i <= n; i ++ ) cin >> a[i];
		
		bool flag = true;
		for (int i = 1; i + 2 <= n; i ++ ) {
			if (a[i] % 2 == a[i + 2] % 2) continue;
			else {
				flag = false;
				break;
			}
		}
		
		if (flag) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
	
	return 0;
}