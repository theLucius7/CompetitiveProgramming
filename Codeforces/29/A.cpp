#include <bits/stdc++.h>

using namespace std;

void solve () {
	int n;
	cin >> n;
	
	vector <int> a(n), b(n);
	for (int i = 0; i < n; i ++ ) {
		cin >> a[i] >> b[i];
	}
	
	for (int i = 0; i < n; i ++ ) {
		for (int j = 0; j < n; j ++ ) {
			if (i != j && a[j] == a[i] + b[i] && a[i] == a[j] + b[j]) {
				cout << "YES\n";
				return;
			}
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