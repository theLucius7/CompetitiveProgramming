#include <bits/stdc++.h>

using i64 = long long;

#define int long long

constexpr int inf = 1E15;

struct DSU {
    std::vector<int> f, siz;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
	
    int size(int x) {
        return siz[find(x)];
    }
};

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	std::cin >> n >> m;

	std::vector<std::array<int, 3>> edges(m);
	for (int i = 0; i < m; i++) {
		std::cin >> edges[i][1] >> edges[i][2] >> edges[i][0];
		edges[i][1]--;
		edges[i][2]--;
	}

	std::sort(edges.begin(), edges.end(), std::greater<>());

	DSU dsu(n);
	std::vector<std::vector<std::pair<int, int>>> adj(n);
	int comp = n;
	for (int i = 0; i < m; i++) {
		if (dsu.merge(edges[i][1], edges[i][2])) {
			adj[edges[i][1]].push_back({edges[i][2], edges[i][0]});
			adj[edges[i][2]].push_back({edges[i][1], edges[i][0]});
			comp--;
		}	
	}

	const int logn = std::__lg(n);
	std::vector pp(logn + 1, std::vector<int>(n, -1));
	std::vector mn(logn + 1, std::vector<int>(n, inf));
	std::vector<int> dep(n, -1);

	auto dfs = [&](this auto &&self, int x, int p) -> void{
		if (p == -1) {
			dep[x] = 0;
		} else {
			dep[x] = dep[p] + 1;
		}
		
		for (int i = 0; (2 << i) <= dep[x] + 1; i++) {
			pp[i + 1][x] = pp[i][pp[i][x]];
			mn[i + 1][x] = std::min(mn[i][x], mn[i][pp[i][x]]);
		}

		for (auto [y, w] : adj[x]) {
			if (y != p) {
				pp[0][y] = x;
				mn[0][y] = w;
				self(y, x);
			}
		}
	};

	for (int i = 0; i < n; i++) {
		if (dep[i] == -1) {
			dfs(i, -1);
		}
	}

	auto query = [&](int x, int y) {
		if (dep[x] < dep[y]) {
			std::swap(x, y);
		}

		int res = inf;
		for (int i = logn; i >= 0; i--) {
			if (dep[x] - (1 << i) >= dep[y]) {
				res = std::min(res, mn[i][x]);
				x = pp[i][x];
			}
		}

		if (x == y) {
			return res;
		}

		for (int i = logn; i >= 0; i--) {
			if (pp[i][x] != pp[i][y]) {
				res = std::min(res, mn[i][x]);
				res = std::min(res, mn[i][y]);
				x = pp[i][x];
				y = pp[i][y];
			}
		}
		res = std::min({res, mn[0][x], mn[0][y]});
		return res;
	};

	int q;
	std::cin >> q;
	while (q--) {
		int x, y;
		std::cin >> x >> y;
		x--, y--;

		if (!dsu.same(x, y)) {
			std::cout << -1 << "\n";
			continue;
		}

		std::cout << query(x, y) << "\n";
	}

	return 0;
}