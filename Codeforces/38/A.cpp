#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve () {
	int n;
	cin >> n;
	
	vector <int> a(n + 1);
	for (int i = 1; i < n; i ++ ) {
		cin >> a[i];
	}
	
	int s, e;
	cin >> s >> e;
	
	int ans = 0;
	
	for (int i = s; i < e; i ++ ) {
		ans += a[i];
	}
	
	cout << ans << "\n";
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();
	
	return 0;
}