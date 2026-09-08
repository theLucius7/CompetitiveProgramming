#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve () {
	int n;
	cin >> n;

	i64 a = 0, b = 0;

	for (int i = 0; i < n; i ++ ) {
		int x;
		cin >> x;

		if (i & 1) {
			a += x;
		} else {
			b += x;
		}
	}

	b *= -1;

	cout << abs (a - b) << "\n";
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