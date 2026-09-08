#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n;
int st[N][N];

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	for (int i = 1; i <= n; i ++ ) {
		string s;
		cin >> s;

		for (int j = 0; j < s.size (); j ++ ) {
			int p = j + 1;

			st[i][p] = s[j];

			if (i != p) {
				if (st[p][i]) {
					if (st[i][p] == 'L' && st[p][i] == 'W' || st[i][p] == 'W' && st[p][i] == 'L' || st[i][p] == 'D' && st[p][i] == 'D') {
						continue;
					} else {
						cout << "incorrect" << "\n";
						return 0;
					}
				}
			}
		}
	}

	cout << "correct" << "\n";

	return 0;
}