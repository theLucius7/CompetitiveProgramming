#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 10;

int n, S, T, m;
int stones[N];
int w[N], f[N];

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> S >> T >> m;

	if (S == T) {
		int res = 0;
		for (int i = 0; i < m; i ++ ) {
			int x;
			cin >> x;

			if (x % S == 0) {
				res ++ ;
			} 
		}

		cout << res << "\n";
	} else {
		for (int i = 0; i < m; i ++ ) {
			cin >> stones[i];
		}

		sort (stones, stones + m);

		int last = 0, k = 0;
		for (int i = 0; i < m; i ++ ) {
			k += min (stones[i] - last, 100);

			w[k] = 1;

			last = stones[i];
		}

		for (int i = 1; i <= k + 10; i ++ ) {
			f[i] = 1e9;
			for (int j = S; j <= T; j ++ ) {
				if (i - j >= 0) {
					f[i] = min (f[i], f[i - j] + w[i]);
				}
			}

		}

		int res = 1e9;
		for (int i = k + 1; i <= k + 10; i ++ ) {
			res = min (res, f[i]);
		}
		
		cout << res << "\n";
	}

	return 0;
}