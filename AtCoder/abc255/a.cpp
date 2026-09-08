#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int x, y;
	cin >> x >> y;

	vector <vector <int>> a(3, vector <int> (3));
	for (int i = 1; i <= 2; i ++ ) {
		for (int j = 1; j <= 2; j ++ ) {
			cin >> a[i][j];
		}
	}

	cout << a[x][y] << "\n";

	return 0;
}