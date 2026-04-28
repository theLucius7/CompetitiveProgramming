#include <bits/stdc++.h>

using namespace std;

const int N = 110, M = 3e6;

int n;
int a[N];
int f[M];

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T -- ) {
		cin >> n;

		for (int i = 0; i < n; i ++ ) {
			cin >> a[i];
		}

		sort (a, a + n);

		memset (f, 0, sizeof f);
		f[0] = 1;

		int res = n;
		for (int i = 0; i < n; i ++ ) {
			if (f[a[i]]) {
				res -- ;
			} else {
				for (int j = a[i]; j <= a[n - 1]; j ++ ) {
					f[j] |= f[j - a[i]];
				}
			}
		}

		cout << res << "\n";
	}

	return 0;
}