#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1000;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T -- ) {
		int n;
		cin >> n;

		string s;
		cin >> s;

		LL res = 0;
		for (int i = 0; i < n; i ++ ) {
			if (s[i] == 'L') {
				res += i;
			} else {
				res += n - 1 - i;
			}
		}

		// cout << res << " ";

		int m = n;
		int l = 0, r = n - 1;

		double mid = (n - 1) * 1.0 / 2;

		for (int i = 0; i < n; i ++ ) {
			while (s[l] == 'R' && l <= mid) {
				l ++ ;
			}

			while (s[r] == 'L' && r >= mid) {
				r -- ;
			}

			if (l >= mid && r <= mid) {
				cout << res << " \n"[i == n - 1];
			} else {
				if (abs (0 - l) <= abs (m - 1 - r)) {
					s[l] = 'R';
					res -= l;
					res += m - 1 - l;
					l ++ ;
				} else {
					s[r] = 'L';
					res -= m - 1 - r;
					res += r;
					r -- ;
				}

				cout << res << " \n"[i == n - 1];
			}
		}

	}

	return 0;
}