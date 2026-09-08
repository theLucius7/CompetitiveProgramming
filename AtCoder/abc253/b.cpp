#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector <string> s(n);
	for (int i = 0; i < n; i ++ ) {
		cin >> s[i];
	}

	int x1, x2, y1, y2;
	bool first = false;
	for (int i = 0; i < n; i ++ ) {
		for (int j = 0; j < m; j ++ ) {
			if (s[i][j] == 'o') {
				if (!first) {
					x1 = i;
					y1 = j;
					first = true;
				} else {
					x2 = i;
					y2 = j;
				}
			}
		}
	}

	int res = abs (x1 - x2) + abs (y1 - y2);
	cout << res << "\n";

	return 0;
}