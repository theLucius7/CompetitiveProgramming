#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve () {
	int x, y, z;
	cin >> x >> y >> z;
	
	if (x < 0) {
		x *= -1, y *= -1, z *= -1;
	} 
	
	if (y < 0 || y > x) {
		cout << x << "\n";
	} else if (z < y) {
		cout << abs (z) + abs (x - z) << "\n"; 
	} else {
		cout << "-1\n";
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();
	
	return 0;
} 