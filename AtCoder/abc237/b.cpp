#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector <vector <int>> a(n, vector <int> (m));
	for (int i = 0; i < n; i ++ ) {
		for (int j = 0; j < m; j ++ ) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < m; i ++ ) {
		for (int j = 0; j < n; j ++ ) {
			cout << a[j][i] << " \n"[j == n - 1];
		}
	}


	return 0;
}