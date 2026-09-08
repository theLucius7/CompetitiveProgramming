#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve () {
	int n;
	cin >> n;
	
	n = abs (n);
	
	int x = -1, m = 0;
	
	while (true) {
		x ++ ;
		m += x;
		if (m == n || (m > n && (m - n) % 2 == 0)) {
			cout << x << "\n";
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