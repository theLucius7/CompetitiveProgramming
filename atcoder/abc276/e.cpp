#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long i64;
typedef pair <int, int> pii;

constexpr int N = 3E6 + 10, M = 5E6 + 10;

int n, m;
string s[N];
map <pii, int> dist;

bool bfs (int x, int y) {
	int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};

	queue <pii> q;
	q.push ({x, y});

	dist[{x, y}] = 1;

	int res = 0;

	while (q.size ()) {
		pii t = q.front ();
		q.pop ();

		for (int i = 0; i < 4; i ++ ) {
			int nx = t.x + dx[i], ny = t.y + dy[i];
			if ((nx >= 0 && nx < n && ny >= 0 && ny < m) && (s[nx][ny] == '.' || s[nx][ny] == 'S') && dist[(pii){nx, ny}] != dist[(pii){t.x, t.y}] - 1) {
				if (dist[{nx, ny}]) {
					cout << "1\n";
					res = max (res, dist[{nx, ny}]);
				} else {
					q.push ({nx, ny});
					dist[{nx, ny}] = dist[{x, y}] + 1;
				}
			}
		}
	}

	// cout << dist[{1, 1}] << " " << dist[{2, 2}];
	cout << res << "\n";

	return res >= 4;
}

void solve () {
	cin >> n >> m;

	for (int i = 0; i < n; i ++ ) {
		cin >> s[i];
	}

	for (int i = 0; i < n; i ++ ) {
		for (int j = 0; j < m; j ++ ) {
			if (s[i][j] == 'S') {
				bool ok = bfs (i, j);
				if (ok) {
					cout << "Yes\n";
				} else {
					cout << "No\n";
				}
				return;
			}
		}
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve ();

	return 0;
}