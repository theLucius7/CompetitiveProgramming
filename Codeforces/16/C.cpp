#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

int gcd (int a, int b) {
	return b == 0 ? a : gcd (b, a % b);
}

void solve () {
	int x, y;
	cin >> x >> y;
	
	int a, b;
	cin >> a >> b;
	
	int d = gcd (a, b);
	a /= d,	b /= d;
	
	if (x < a || y < b) {
		cout << "0 0\n";
	} else {
		int t = min (x / a, y / b);
		cout << t * a << " " << t * b << "\n";
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();
	
	return 0;
}