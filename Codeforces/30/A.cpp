#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve () {
	int a, b, n;
	cin >> a >> b >> n;
	
	for (int i = -abs (b); i <= abs (b); i ++ ) {
		if (a * pow (i, n) == b) {
			cout << i << "\n";
			return;
		}
	}
	
	cout << "No solution\n";
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();
	
	return 0;
} 