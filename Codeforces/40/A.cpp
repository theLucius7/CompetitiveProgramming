#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve () {
	int x, y;
	cin >> x >> y;
	
	int r = sqrt (x * x + y * y);
	
	if (r % 2 == 0 && x * y > 0 || r % 2 == 1 && x * y < 0 || r * r == x * x + y * y) {
		cout << "black\n";
	} else {
		cout << "white\n";
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();
	
	return 0;
}