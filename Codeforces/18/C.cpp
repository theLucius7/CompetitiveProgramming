#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve () {
	int n;
	cin >> n;
	
	vector <int> a(n + 1), s(n + 1); 
	
	for (int i = 1; i <= n; i ++ ) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	
	int ans = 0;
	
	for (int i = 1; i < n; i ++ ) {
		if (s[i] == s[n] - s[i]) {
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