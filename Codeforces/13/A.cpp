#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

int calc (int p, int x) {
	int res = 0;
	while (x) {
		res += x % p;
		x /= p;
	}
	return res;
}

int gcd (int a, int b) {
	return b == 0 ? a : gcd (b, a % b);
}

void solve () {
	int n;
	cin >> n;
	
	int a = 0;
	for (int i = 2; i < n; i ++ ) {
		a += calc (i, n);
	}
	
	int b = n - 2;
	
	int d = gcd (a, b);
	
	cout << a / d << "/" << b / d << "\n";
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();
	
	return 0;
}