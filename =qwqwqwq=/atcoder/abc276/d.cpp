#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

int gcd (int a, int b) {
	return b == 0 ? a : gcd (b, a % b);
}

void solve () {
	int n;
	cin >> n;

	vector <int> a(n);
	for (int i = 0; i < n; i ++ ) {
		cin >> a[i];
	}

	int d = 0;
	for (int i = 0; i < n; i ++ ) {
		d = gcd (d, a[i]);
	}

	int ans = 0;

	for (int i = 0; i < n; i ++ ) {
		a[i] /= d;
		while (a[i] % 2 == 0) {
			ans ++ ;
			a[i] /= 2;
		}

		while (a[i] % 3 == 0) {
			ans ++ ;
			a[i] /= 3;
		}

		if (a[i] != 1) {
			cout << "-1\n";
			return;
		}
	}

	cout << ans << "\n";
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve ();

	return 0;
}