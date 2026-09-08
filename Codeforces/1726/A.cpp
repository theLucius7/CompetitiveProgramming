#include <bits/stdc++.h>

using namespace std;

const int N = 2010;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T -- ) {
		int n;
		cin >> n;

		int a[N];

		int res = 0;
		for (int i = 0; i < n; i ++ ) {
			cin >> a[i];	
		}

		for (int i = 1; i < n; i ++ ) {
			res = max (res, a[((i - 1) % n + n) % n] - a[i]);
		}
		res = max (res, a[n - 1] - a[0]);

		for (int i = 1; i < n; i ++ ) {
			res = max (res, a[i] - a[0]);
		}

		for (int i = 0; i < n - 1; i ++ ) {
			res = max (res, a[n - 1] - a[i]);
		}

		cout << res << "\n";
	}

	return 0;
}