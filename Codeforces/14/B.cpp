#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

constexpr int N = 1010, inf = 1E9; 

void solve () {
	vector <int> a(N);
	
	int n, m;
	int minn = inf, maxn = 0;
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i ++ ) {
		int l, r;
		cin >> l >> r;
		
		if (l > r) {
			swap (l, r); 
		}
		
		for (int j = l; j <= r; j ++ ) {
			a[j] ++ ;
		}
		
		minn = min (minn, l);
		maxn = max (maxn, r);
	} 
	
	int ans = inf;
	for (int i = minn; i <= maxn; i ++ ) {
		if (a[i] == n) {
			ans = min (ans, abs (i - m));
		}
	}
	
	if (ans == inf) {
		cout << "-1\n";
	} else {
		cout << ans << "\n";
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();
	
	return 0;
}