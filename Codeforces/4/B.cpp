#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve () {
	int n, m;
	cin >> n >> m;
	
	vector <int> a(n), b(n);
	int sa = 0, sb = 0;
	
	for (int i = 0; i < n; i ++ ) {
		cin >> a[i] >> b[i];
		sa += a[i];
		sb += b[i];
	} 
	
	if (m >= sa && m <= sb) {
		cout << "YES\n";
		
		m -= sa;
		
		vector <int> ans(n); 
		
		int idx = 0;
		
		while (m) {
			if (m > b[idx] - a[idx]) {
				m -= b[idx] - a[idx];
				ans[idx] = b[idx];
			} else {
				ans[idx] = a[idx] + m;
				m = 0;
			}
			idx ++ ;
		}

		for (int i = idx; i < n; i ++ ) {
			ans[i] = a[i];
		}
		
		for (int i = 0; i < n; i ++ ) {
			cout << ans[i] << " \n"[i == n - 1];
		} 
	} else {
		cout << "NO\n";
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();
	
	return 0;
}