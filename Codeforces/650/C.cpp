#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

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

    std::vector g(n, std::vector<int>(m));
    std::map<int, std::vector<int>> mp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> g[i][j];
            mp[g[i][j]].push_back(i * m + j);
        }
    }

    std::vector<int> mx(n + m, 1);
    std::vector ans(n, std::vector<int>(m));
    DSU dsu(n + m);
    for (auto &[_, v] : mp) {
        for (int i = 0; i < v.size(); i++) {
            int x = v[i] / m, y = v[i] % m;
            dsu.f[x] = x;
            dsu.f[n + y] = n + y;
            dsu.siz[x] = 1;
            dsu.siz[n + y] = 1;
        }

        for (int i = 0; i < v.size(); i++) {
            int x = v[i] / m, y = v[i] % m;
            dsu.merge(x, n + y);
        }

        std::map<int, int> nmx;
        for (int i = 0; i < v.size(); i++) {
            int x = v[i] / m, y = v[i] % m;
            nmx[dsu.find(x)] = std::max({nmx[dsu.find(x)], mx[x], mx[n + y]});
        }

        for (int i = 0; i < v.size(); i++) {
            int x = v[i] / m, y = v[i] % m;
            ans[x][y] = nmx[dsu.find(x)];
            mx[x] = ans[x][y] + 1;
            mx[n + y] = ans[x][y] + 1;
        }
    }

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            std::cout << ans[x][y] << " \n"[y == m - 1];
        }
    }

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
