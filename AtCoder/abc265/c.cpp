#include <bits/stdc++.h>

using namespace std;

const int N = 510;

int n, m;
string g[N];
bool st[N][N];
bool ok = true;
int a, b;

void dfs (int x, int y) {
	if (st[x][y]) {
		ok = false;
		return;
	}

	st[x][y] = true;

	int nx = x, ny = y;
	if (g[x][y] == 'L') {
		ny -- ;
	} else if (g[x][y] == 'R') {
		ny ++ ;
	} else if (g[x][y] == 'U') {
		nx -- ;
	} else {
		nx ++ ;
	}

	if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
		dfs (nx, ny);
	} else {
		a = x + 1, b = y + 1;
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (int i = 0; i < n; i ++ ) {
		cin >> g[i];
	}

	dfs (0, 0);

	if (ok) {
		cout << a << " " << b << "\n";
	} else {
		cout << "-1\n";
	}

	return 0;
}