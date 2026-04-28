#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

constexpr int N = 55, inf = 1E9;

int n, m;
int x[N], y[N];
int ans;

struct Rec {
	int lx, ly, rx, ry;
	bool used;

	int area () {
		if (!used) {
			return 0;
		}
		return (rx - lx) * (ry - ly);
	}

	void add (int x, int y) {
		if (!used) {
			used = true;
			lx = rx = x;
			ly = ry = y;
		} else {
			lx = min (lx, x);
			rx = max (rx, x);
			ly = min (ly, y);
			ry = max (ry, y);
		}
	}

	bool have (int x, int y) {
		if (x >= lx && x <= rx && y >= ly && y <= ry) {
			return true;
		}
		return false;
	}

	bool cross (Rec u) {
		if (!used || !u.used) {
			return false;
		}

		return u.have (lx, ly) || u.have (lx, ry) || u.have (rx, ly) || u.have (rx, ry);
	}

} g[N];

bool check () {
	for (int i = 0; i < m; i ++ ) {
		for (int j = i + 1; j < m; j ++ ) {
			if (g[i].cross (g[j])) {
				return false;
			}
		}
	}
	return true;
}

void dfs (int u,int area) {
	if (area >= ans) {
		return;
	}

	if (u == n) {
		if (check ()) {
			ans = min (ans, area);
		}
		return;
	} 

	for (int i = 0; i < m; i ++ ) {
		Rec t = g[i];
		g[i].add (x[u], y[u]);

		dfs (u + 1, area - t.area () + g[i].area ());

		g[i] = t;
	}
	
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;

	for (int i = 0; i < n; i ++ ) {
		cin >> x[i] >> y[i];
	}
	
	ans = inf;

	dfs (-1, 0);

	cout << ans << "\n";
	
	return 0;
}
