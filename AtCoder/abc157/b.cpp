#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector <vector <int>> a(3, vector <int> (3));
	for (int i = 0; i < 3; i ++ ) {
		for (int j = 0; j < 3; j ++ ) {
			cin >> a[i][j];
		}
	}

	int n;
	cin >> n;

	vector <int> b(n);
	for (int i = 0; i < n; i ++ ) {
		cin >> b[i];
	}

	vector <vector <int>> st(3, vector <int> (3));
	for (int i = 0; i < 3; i ++ ) {
		for (int j = 0; j < 3; j ++ ) {
			for (int k = 0; k < n; k ++ ) {
				if (a[i][j] == b[k]) {
					st[i][j] = true;
				}
			}
		}
	}

	bool res = false;
	for (int i = 0; i < 3; i ++ ) {
		if ((st[0][i] && st[1][i] && st[2][i]) || (st[i][0] && st[i][1] && st[i][2])) {
			res = true;
		}
	}
	if ((st[0][0] && st[1][1] && st[2][2]) || (st[0][2] && st[1][1] && st[2][0])) {
		res = true;
	}

	if (res) {
		cout << "Yes" << "\n";
	} else {
		cout << "No" << "\n";
	}

	return 0;
}