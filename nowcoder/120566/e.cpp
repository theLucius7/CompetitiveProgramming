#include <bits/stdc++.h>

using i64 = long long;

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

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m, x, d;
	std::cin >> n >> m >> x >> d;

	std::vector<std::pair<int, int>> h(n);
	for (int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		h[i] = {x, i};
	}
	std::sort(h.begin(), h.end());

	std::vector<std::vector<int>> adj(n);
	for (int i = 0; i < m; i++) {
		int x, y;
		std::cin >> x >> y;
		x--, y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	std::vector<std::pair<int, int>> H(x);
	for (int i = 0; i < x; i++) {
		int u;
		std::cin >> u;
		H[i] = {u, i};
	}
	std::sort(H.begin(), H.end(), std::greater<>());

	DSU dsu(n);
	auto r = h.end();
	int cnt = 0;
	std::vector<int> ans(x);
	std::vector<bool> st(n);
	for (int i = 0; i < x; i++) {
		auto it = std::upper_bound(h.begin(), h.end(), std::make_pair(H[i].first, n));

		for (auto i = it ; i < r; i++) {
			int X = (*i).second;
			if (st[X]) {
				continue;
			}

			if (!st[X] && dsu.size(X) >= d) {
				cnt++;
			}
			st[X] = true;

			for (int y : adj[X]) {
				if (st[y]) {
					if (dsu.same(X, y)) {
						continue;
					}

					if (dsu.size(X) >= d) {
						cnt--;
					}
					if (dsu.size(y) >= d) {
						cnt--;
					}

					dsu.merge(X, y);

					if (dsu.size(X) >= d) {
						cnt++;
					}
				}
			}

		}
		ans[H[i].second] = cnt;
		r = it;		

	}

	for (int i = 0; i < x; i++) {
		std::cout << ans[i] << "\n";
	}

	return 0;
}