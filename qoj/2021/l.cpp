#include <bits/stdc++.h>

using i64 = long long;
using namespace std;

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
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    DSU dsu(n);
    std::vector<std::pair<int, int>> cut;
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i]--;
        if (!dsu.merge(i, a[i])) {
            cut.emplace_back(i, a[i]);
        } else {
            adj[i].push_back(a[i]);
            adj[a[i]].push_back(i);
        }
    }

    int ban = -1;
    std::vector<int> f(n), g(n);
    auto dfs = [&](auto self, int x, int fa) -> void{
        f[x] = 1;
        g[x] = 0;
        for (auto y : adj[x]) {
            if (y != fa) {
                self(self, y, x);
                f[x] += g[y];
                g[x] += std::max(f[y], g[y]);
            }
        }
        if (x == ban) {
            f[x] = g[x];
        }
    };

    int ans = 0;
    for (auto [x, y] : cut) {
        int max = 0;

        ban = x;
        dfs(dfs, x, -1);
        max = std::max({max, f[x], g[x]});

        ban = y;
        dfs(dfs, x, -1);
        max = std::max({max, f[x], g[x]});

        ans += max;

    }
    std::cout << ans << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    t = 1;
    // std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
