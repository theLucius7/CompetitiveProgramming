#include <bits/stdc++.h>

using i64 = long long;

struct Info {
	int mxpre = 0;
	int mxsuf = 0;
	int mx = 0;
	int mnpre = 0;
	int mnsuf = 0;
	int mn = 0;
	int sum = 0;
};

Info operator+(Info a, Info b) {
	Info c;
	c.mxpre = std::max(a.mxpre, a.sum + b.mxpre);
	c.mxsuf = std::max(b.mxsuf, a.mxsuf + b.sum);
	c.mx = std::max({a.mx, b.mx, a.mxsuf + b.mxpre});
	c.mnpre = std::min(a.mnpre, a.sum + b.mnpre);
	c.mnsuf = std::min(b.mnsuf, a.mnsuf + b.sum);
	c.mn = std::min({a.mn, b.mn, a.mnsuf + b.mnpre});
	c.sum = a.sum + b.sum;
	return c;
}

Info rev(Info a) {
	std::swap(a.mxpre, a.mxsuf);
	std::swap(a.mnpre, a.mnsuf);
	return a;
}

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> p{-1}, x{1};
	std::vector<std::array<int, 3>> qry;
	for (int i = 0; i < n; i++) {
		char o;
		std::cin >> o;
		if (o == '+') {
			int v, xi;
			std::cin >> v >> xi;
			v--;
			p.push_back(v);
			x.push_back(xi);
		} else {
			int u, v, k;
			std::cin >> u >> v >> k;
			u--, v--;
			qry.push_back({u, v, k});
		}
	}

	n = p.size();
	const int logn = std::__lg(n);
	std::vector<int> depth(n);
	std::vector pp(logn + 1, std::vector<int>(n, -1));
	std::vector f(logn + 1, std::vector<Info>(n));
	for (int i = 0; i < n; i++) {
		if (i > 0) {
			depth[i] = depth[p[i]] + 1;
		}

		pp[0][i] = p[i];
		if (x[i] == 1) {
			f[0][i].mxpre = f[0][i].mxsuf = f[0][i].mx = f[0][i].sum = 1;
		} else {
			f[0][i].mnpre = f[0][i].mnsuf = f[0][i].mn = f[0][i].sum = -1;
		}

		for (int j = 0; (2 << j) <= depth[i] + 1; j++) {
			pp[j + 1][i] = pp[j][pp[j][i]];
			f[j + 1][i] = f[j][i] + f[j][pp[j][i]];
		}
	}

	auto query = [&](int x, int y) {
		if (depth[x] < depth[y]) {
			std::swap(x, y);
		}

		Info l, r;
		for (int i = logn; i >= 0; i--) {
			if (depth[x] - (1 << i) >= depth[y]) {
				l = l + f[i][x]; 
				x = pp[i][x];
			}
		}

		if (x == y) {
			return l + f[0][x];
		}

		for (int i = logn; i >= 0; i--) {
			if (pp[i][x] != pp[i][y]) {
				l = l + f[i][x];
				r = r + f[i][y];
				x = pp[i][x];
				y = pp[i][y];
			}
		}
		return l + f[1][x] + f[0][y] + rev(r);
	};

	for (auto [u, v, k] : qry) {
		auto info = query(u, v);
		std::cout << (info.mn <= k && k <= info.mx ? "YES" : "NO") << "\n";
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}
	

	return 0;
}