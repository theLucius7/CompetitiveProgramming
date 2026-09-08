#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve () {
	int n;
	cin >> n;
	
	vector <int> a(n);
	for (int i = 0; i < n; i ++ ) {
		cin >> a[i];
	}
	
	i64 ans = 0;
	for (int i = 0; i < n; i ++ ) {
		ans += a[i] + 1LL * i * (a[i] - 1);
	}
	
	cout << ans << "\n";
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();
	
	return 0;
} 