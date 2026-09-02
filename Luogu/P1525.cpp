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

    int n, m;
    std::cin >> n >> m;

    std::vector<std::tuple<int, int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        int x, y, w;
        std::cin >> x >> y >> w;
        x--, y--;
        edges[i] = {w, x, y};
    }

    std::sort(edges.begin(), edges.end(), std::greater<std::tuple<int, int, int>>());

    
    auto A = [&](int x) {
        return x;
    };
    auto B = [&](int x) {
        return x + n;
    };
    DSU dsu(2 * n);

    for (int i = 0; i < m; i++) {
        auto [w, x, y] = edges[i];
        if (dsu.same(x, y)) {
            std::cout << w << "\n";
            return 0;
        }

        dsu.merge(A(x), B(y));
        dsu.merge(B(x), A(y));
    }
    std::cout << 0 << "\n";

	return 0;
}