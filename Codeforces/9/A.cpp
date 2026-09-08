#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

int gcd (int a, int b) {
	return b == 0 ? a : gcd (b, a % b);
}

void solve () {
	int a, b;
	cin >> a >> b;
	
	int m = 6 - max (a, b) + 1, n = 6;
	cout << m / gcd (n, m) << "/" << n / gcd (n, m) << "\n";
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();
	
	return 0;
}