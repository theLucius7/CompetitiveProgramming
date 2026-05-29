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

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<std::tuple<int, int, int>> edges;
    for (int i = 0; i < n; i++) {
        edges.emplace_back(a[i], 0, i + 1);
    }
    for (int i = 1; i < n; i++) {
        edges.emplace_back(std::abs(a[i] - a[i - 1]), i, i + 1);
    }

    std::sort(edges.begin(), edges.end());

    DSU dsu(n + 1);
    int cnt = 0;
    for (int i = 0; i < edges.size(); i++) {
        auto [w, x, y] = edges[i];
        if (!dsu.same(x, y)) {
            dsu.merge(x, y);
            cnt++;

            if (cnt == n) {
                std::cout << w << "\n";
            }
        }
    }


	return 0;
}