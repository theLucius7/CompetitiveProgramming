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
    std::map<int, std::vector<std::pair<int, int>>> pos;
    std::vector ps(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> g[i][j];
            pos[g[i][j]].push_back({i, j});
            ps[i][j] = pos[g[i][j]].size() - 1;
        }
    }

    int dx[] = {1, 1, 1, -1, -1, -1, 0, 0}, dy[] = {1, 0, -1, 1, 0, -1, 1, -1};

    for (int ans = 0; ; ans++) {
        auto &v = pos[ans];

        DSU dsu(v.size() + 2);
        for (int i = 0; i < v.size(); i++) {
            int x = v[i].first, y = v[i].second;
            if (x == 0 || y == m - 1) {
                dsu.merge(v.size(), i);
            }
            if (x == n - 1 || y == 0) {
                dsu.merge(v.size() + 1, i);
            }

            for (int j = 0; j < 8; j++) {
                int nx = x + dx[j], ny = y + dy[j];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && g[nx][ny] == ans) {
                    dsu.merge(i, ps[nx][ny]);
                }
            }
        }

        if (!dsu.same(v.size(), v.size() + 1)) {
            std::cout << ans << "\n";
            return;
        }
    }


}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
