#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve () {
	int n, m;
	cin >> n >> m;
	
	vector <int> a(n);
	
	for (int i = 0; i < n; i ++ ) {
		cin >> a[i];
	}
	
	sort (a.begin (), a.end ());
	
	int ans = 0;
	
	for (int i = 0; i < m && i < n; i ++ ) {
		if (a[i] < 0) {
			ans += abs (a[i]);
		} else {
			break;
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