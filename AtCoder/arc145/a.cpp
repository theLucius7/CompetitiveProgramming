#include <bits/stdc++.h>

using namespace std;

int n;
string s, p;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> s;

	p = s;

	reverse (s.begin (), s.end ());

	if (p == s) {
		cout << "Yes\n";
	} else {
		if (n == 3) {
			if ((p[0] == 'B' && p[1] == 'A') || (p[1] == 'B' && p[2] == 'A')) {
				cout << "Yes\n";
			} else {
				cout << "No\n";
			}
		} else {
			int lmid = (n - 1) / 2;

			if (n % 2) {
				lmid -- ;
			}

			int rmid = n - 1 - lmid;

			string str;
			for (int i = 0; i <= lmid; i ++ ) {
				if (i % 2 == 0) {
					str += 'A';
				} else {
					str += 'B';
				}
			}

			reverse (str.begin (), str.end ());

			bool ok = true;
			for (int i = 0; i <= lmid; i ++ ) {
				if (str[i] != p[i]) {
					ok = false;
				}
			}

			if (ok) {
				cout << "Yes\n";
				return 0;
			}

			ok = true;
			for (int i = rmid, j = 0; i < n; i ++ , j ++ ) {
				if (str[j] != p[i]) {
					ok = false;
				}
			}

			if (ok) {
				cout << "Yes\n";
				return 0;
			}

			cout << "No\n";
		}
		
	}

	return 0;
}