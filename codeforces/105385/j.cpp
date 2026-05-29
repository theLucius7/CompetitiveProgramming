#include <bits/stdc++.h>

#define int long long

using i64 = long long;

using real = long double;

using namespace std;

struct DSU {
	int n;
	vector<int> f;
	DSU(int _n) {
		n = _n;
		f.resize(n + 1);
		iota(f.begin(), f.end(), 0);
	}

	int find(int x) {
		while (x != f[x]) {
			x = f[x] = f[f[x]];
		}
		return x;
	}

	bool merge(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) {
			return false;
		}
		f[y] = x;
		return true;
	}

	bool same(int x, int y) {
		return find(x) == find(y);
	}
};

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i ++ ) {
		cin >> a[i];
	}
	vector<vector<int>> b(n + 1, vector<int>(n + 1));
	for (int i = 1; i <= n; i ++ ) {
		for (int j = 1; j <= n; j ++ ) {
			cin >> b[i][j];
		}
	}
	DSU dsu(n + 1);
	vector<array<int, 3>> e(n * n);
	for (int i = 1; i <= n; i ++ ) {
		for (int j = 1; j <= n; j ++ ) {
			e[(i - 1) * n + j - 1] = {b[i][j], i, j};
		}
	}
	sort(e.begin(), e.end());
	int ans = 0;
	for (auto [w, u, v] : e) {
		if (!dsu.same(u, v)) {
			dsu.merge(u, v);
			ans += w;
		}
	}
	// cout << ans << endl;
	for (int i = 1; i <= n; i ++ ) {
		for (int j = 1; j <= n; j ++ ) {
			b[i][1] = min(b[i][1], b[i][j]);
		}
		ans += (a[i] - 1) * b[i][1];
	}
	cout << ans << endl;
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int T = 1;
	cin >> T;
	while (T -- ) {
		solve();
	}

	return 0;
}