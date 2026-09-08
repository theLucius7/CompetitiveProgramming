#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	int T;
	cin >> T;

	while (T -- ) {
		int n;
		cin >> n;

		vector <int> a(n), b(n);
		for (int i = 0; i < n; i ++ ) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i ++ ) {
			cin >> b[i];
		}

		int l = 0, r = INF;
		for (int i = 0; i < n; i ++ ) {
			if (b[i] == 0) {
				l = max (l, a[i] - 0);
			} else {
				l = max (l, a[i] - b[i]);
				r = min (r, a[i] - b[i]);
			}
		}

		if (r >= l) {
			cout << "YES" << "\n";
		} else {
			cout << "NO" << "\n";
		}
	}


	return 0;
}