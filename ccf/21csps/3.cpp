#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int n;
int a[N];
char s[N];
bool ok = false;

void dfs (int u, int l, int r, int L, int R) {
	if (l > r && L > R) {
		ok = true;
		for (int i = 1; i <= 2 * n; i ++ ) {
			cout << s[i];
		}
		cout << "\n";
		return;
	}

	if (l <= r && (a[l] == a[r] && l < r || a[l] == a[L] && L <= R)) {
		s[u] = 'L';
		if (a[l] == a[r] && l < r) {
			s[2 * n - u + 1] = 'L';
			dfs (u + 1, l + 1, r - 1, L, R);
		} else {
			s[2 * n - u + 1] = 'R';
			dfs (u + 1, l + 1, r, L + 1, R);
		}
	} else if (L <= R && (a[R] == a[L] && L < R || a[R] == a[r] && l <= r)) {
		s[u] = 'R';
		if (a[R] == a[r] && l <= r) {
			s[2 * n - u + 1] = 'L';
			dfs (u + 1, l, r - 1, L, R - 1);
		} else {
			s[2 * n - u + 1] = 'R';
			dfs (u + 1, l, r, L + 1, R - 1);
		}
	}

}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T -- ) {
		cin >> n;
		
		for (int i = 1; i <= 2 * n; i ++ ) {
			cin >> a[i];
		}

		ok = false;

		s[2 * n] = 'L';

		for (int i = 2; i <= 2 * n; i ++ ) {
			if (a[i] == a[1]) {
				s[1] = 'L';
				dfs (2, 2, i - 1, i + 1, 2 * n);
				break;
			}
		}

		if (!ok) {
			for (int i = 2 * n - 1; i >= 1; i -- ) {
				if (a[i] == a[2 * n]) {
					s[1] = 'R';
					dfs (2, 1, i - 1, i + 1, 2 * n - 1);
					break;
				}
			}
		}

		if (!ok) {
			cout << "-1\n";
		}
	}

	return 0;
}