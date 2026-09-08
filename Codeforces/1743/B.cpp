#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve () {
	int n;
	cin >> n;

	int l = 1, r = n;

	for (int i = 1; i <= n; i ++ ) {
		if (i & 1) {
			cout << l << " ";
			l ++ ;
		} else {
			cout << r << " ";
			r -- ;
		}
	}

	cout << "\n";
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