// LUOGU_RID: 92276955
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

int gcd (int a, int b) {
	return b == 0 ? a : gcd (b, a % b);
}

void solve () {
	int n;
	cin >> n;

	int d = 0;
	vector <int> a(n);

	for (int i = 0; i < n; i ++ ) {
		cin >> a[i];
		d = gcd (d, a[i]);
	}
	
	if (d == 1) {
		cout << "0\n";
	} else if (gcd (n, d) == 1) {
		cout << "1\n";
	} else if (gcd (n - 1, d) == 1) {
		cout << "2\n";
	} else {
		cout << "3\n";
	}

}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T -- ) {
		solve ();
	}

	return 0;
}