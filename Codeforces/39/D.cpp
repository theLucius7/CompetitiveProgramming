#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve () {
	array <int, 3> a, b;
	for (int i = 0; i < 3; i ++ ) {
		cin >> a[i];
	}
	for (int i = 0; i < 3; i ++ ) {
		cin >> b[i];
	}
	
	int cnt = 0;
	for (int i = 0; i < 3; i ++ ) {
		if (a[i] == b[i]) {
			cout << "YES\n";
			return;
		}
	}
	
	cout << "NO\n";
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();
	
	return 0;
}