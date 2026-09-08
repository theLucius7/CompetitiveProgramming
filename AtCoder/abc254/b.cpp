#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector <vector <int>> a(n, vector <int> (n));
	for (int i = 0; i < n; i ++ ) {
		a[i][0] = 1;
		for (int j = 1; j <= i; j ++ ) {
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
		}

		for (int j = 0; j <= i; j ++ ) {
			cout << a[i][j] << " \n"[i == j];
		}

	}


	return 0;
}