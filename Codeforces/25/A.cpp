#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve () {
	int n;
	cin >> n;
	
	vector <int> a(n);
	
	cin >> a[0] >> a[1] >> a[2];
	
	int t = (a[0] % 2 + a[1] % 2 + a[2] % 2) / 2;
	
	for (int i = 0; i < n; i ++ ) {
		if (i >= 3) {
			cin >> a[i];
		}
		
		if (a[i] % 2 != t) {
			cout << i + 1 << "\n";
			break;
		}
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();
	
	return 0;
}