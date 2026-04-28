#include <bits/stdc++.h>

using namespace std;

const int N = 2010;

int k;
int c[N][N];
int s[N][N];

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T >> k;

	for (int i = 0; i <= 2000; i ++ ) {
		for (int j = 0; j <= i; j ++ ) {
			if (j == 0) {
				c[i][j] = 1;
			} else{
				c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % k;
			}

			if (c[i][j] == 0) {
				s[i + 1][j + 1] ++ ;
			}
		}
	}

	for (int i = 0; i <= 2000; i ++ ) {
		for (int j = 0; j <= 2000; j ++ ) {
			s[i + 1][j + 1] += s[i][j + 1] + s[i + 1][j] - s[i][j];
		}
	}


	while (T -- ) {
		int n, m;
		cin >> n >> m;

		if (m > n) {
			cout << s[n + 1][n + 1] << "\n";
		} else {
			cout << s[n + 1][m + 1] << "\n";
		}
	}

	return 0;
}