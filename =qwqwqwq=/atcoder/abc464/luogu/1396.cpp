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

    int n, m, s, t;
    std::cin >> n >> m >> s >> t;
    s--, t--;

    std::vector<std::tuple<int, int, int>> v(m);
    for (int i = 0; i < m; i++) {
        int u, x, y;
        std::cin >> x >> y >> u;
        x--, y--;
        v[i] = {u, x, y};
    }

    std::sort(v.begin(), v.end());

    DSU dsu(n);
    for (int i = 0; i < m; i++) {
        auto [u, x, y] = v[i];
        dsu.merge(x, y);
        if (dsu.same(s, t)) {
            std::cout << u << "\n";
            return 0;
        }
    }

	return 0;
}