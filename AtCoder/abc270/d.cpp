#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve () {
	int n, m;
	cin >> m >> n;
	
	vector <int> a(n);
	for (int i = 0; i < n; i ++ ) {
		cin >> a[i];
	}
	
	vector <int> f(m + 1);
	for (int i = 1; i <= m; i ++ ) {
		for (int j = 0; j < n; j ++ ) {
			if (i >= a[j]) {
				f[i] = max (f[i], i - f[i - a[j]]);
			}
		}
	}
	
	cout << f[m] << "\n";
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();
	
	return 0;
} 