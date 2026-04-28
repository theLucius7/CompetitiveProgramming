#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef pair <int, int> PII;

const int N = 310, M = 2 * N;

int n, m;
int h[N], e[M], ne[M], idx;
vector <int> level[N];
int cnt[N];
int c[N];
int res = N;

void add (int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

int dfs_level (int u, int depth, int father) {
	cnt[u] = 1;

	for (int i = h[u]; ~i; i = ne[i]) {
		int j = e[i];
		if (j != father) {
			cnt[u] += dfs_level (j, depth + 1, u);
			level[depth].push_back (i);
		}
	}

	return cnt[u];
}

void dfs_draw (int j, int color) {
	c[j] = color;
	for (int i = h[e[j]]; ~i; i = ne[i]) {
		if (i != (j ^ 1)) {
			dfs_draw (i, color);
		}
	}
}

void dfs (int u, int s) {
	res = min (res, s);

	for (int i = 0; i < level[u].size (); i ++ ) {
		int j = level[u][i];
		if (c[j] == 0) {
			dfs_draw (j, 1);
			dfs (u + 1, s - cnt[e[j]]);
			dfs_draw (j, 0);
		}
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	memset (h, -1, sizeof h);

	for (int i = 0; i < m; i ++ ) {
		int a, b;
		cin >> a >> b;

		add (a, b);
		add (b, a);
	}

	dfs_level (1, 0, -1);

	dfs (0, n);

	cout << res << "\n";

	return 0;
}