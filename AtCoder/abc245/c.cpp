#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, K;
	cin >> n >> K;

	int a[2][n];
	memset (a, 0, sizeof a);
	for (int i = 0; i < 2; i ++ ) {
		for (int j = 0; j < n; j ++ ) {
			cin >> a[i][j];
		}
	}

	bool f[n][2];
	memset (f, false, sizeof f);
	f[0][0] = f[0][1] = true;

	for (int i = 1; i < n; i ++ ) {
		for (int j = 0; j < 2; j ++ ) {
			for (int k = 0; k < 2; k ++ ) {
				if (f[i - 1][j] && abs (a[j][i - 1] - a[k][i]) <= K) {
					f[i][k] = true;
				}
			}
		}
	}

	if (f[n - 1][0] || f[n - 1][1]) {
		cout << "Yes" << "\n";
	} else {
		cout << "No" << "\n";
	}

	return 0;
}