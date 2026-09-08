#include <bits/stdc++.h>

using namespace std;

void solve () {
	int n;
	cin >> n;
	
	vector <int> cnt(n + 1);
	cnt[1] = 1;
	
	for (int i = 1; i <= n; i ++ ) {
		if (cnt[i] == 0) {
			for (int j = 2; j * i <= n; j ++ ) {
				cnt[i * j] ++ ;
			}
		}
	}
	
	int ans = 0;
	
	for (int i = 1; i <= n; i ++ ) {
		if (cnt[i] == 2) {
			ans ++ ;
		}
	}
	
	cout << ans << "\n";
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();
	
	
	return 0;
}