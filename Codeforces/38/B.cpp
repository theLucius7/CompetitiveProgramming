#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2}, dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

void solve () {
	vector <vector <bool>> st(9, vector <bool> (9));

	string s;

	cin >> s;
	int x1 = s[0] - 'a' + 1, y1 = s[1] - '0';

	cin >> s;
	int x2 = s[0] - 'a' + 1, y2 = s[1] - '0';

	for (int i = 1; i <= 8; i ++ ) {
		st[x1][i] = st[i][y1] = true;
	}

	for (int i = 0; i < 8; i ++ ) {
		int nx = x1 + dx[i];
		int ny = y1 + dy[i];

		if (nx >= 1 && nx <= 8 && ny >= 1 && ny <= 8) {
			st[nx][ny] = true;
		}
	}

	st[x2][y2] = true;

	for (int i = 0; i < 8; i ++ ) {
		int nx = x2 + dx[i];
		int ny = y2 + dy[i];

		if (nx >= 1 && nx <= 8 && ny >= 1 && ny <= 8) {
			st[nx][ny] = true;
		}
	}

	int cnt = 0;

	for (int i = 1; i <= 8; i ++ ) {
		for (int j = 1; j <= 8; j ++ ) {
			if (!st[i][j]) {
				cnt ++ ;
			}
		}
	}

	cout << cnt << "\n";

}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();
	
	return 0;
} 