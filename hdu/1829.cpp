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

void solve() {
    int n, m;
    std::cin >> n >> m;

    DSU dsu(2 * n);
    auto F = [&](int x) {
        return x;
    };
    auto M = [&](int x) {
        return x + n;
    };

    while (m--) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        dsu.merge(F(x), M(y));
        dsu.merge(M(x), F(y));
    }

    for (int i = 0; i < n; i++) {
        if (dsu.same(F(i), M(i))) {
            std::cout << "Suspicious bugs found!\n";
            return;
        }
    }
    std::cout << "No suspicious bugs found!\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        std::cout << "Scenario #" << i + 1 << ":\n";
        solve();
        std::cout << "\n";
    }

	return 0;
}