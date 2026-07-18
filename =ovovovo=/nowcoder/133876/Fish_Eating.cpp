#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

struct DSU {
    std::vector<int> f, g;
    std::vector<int> siz;

    int ans = 0;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        g.assign(n, 0);
        siz.assign(n, 1);
    }
    
    int find(int x) {
        if (f[x] == x) {
            return x;
        }

        find(f[x]);
        g[x] = std::max(g[x], g[f[x]]);
        f[x] = f[f[x]];
        
        return f[x];
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y, int v) {
        find(x);
        find(y);
        x = f[x];
        y = f[y];

        if (x == y) {
            return false;
        }
        
        f[y] = x;
        g[y] = std::max(0LL, v - (siz[y] - 1));

        siz[x] += siz[y];

        return true;
    }
};

void solve() {
    int n, m, q;
    std::cin >> n >> m >> q;

    DSU dsu(n * m);
    std::vector<int> vec(n * m);

    int l = 0;
    int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};

    while (q--) {
        int op;
        std::cin >> op;

        if (op == 1) {
            int x, y;
            std::cin >> x >> y;
            x ^= l, y ^= l;
            x--, y--;
            int pos = x * m + y;
            std::cin >> vec[pos];

            for (int _ = 0; _ < 4; _++) {
                int nx = x + dx[_], ny = y + dy[_];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    continue;
                }

                int npos = nx * m + ny;

                if (vec[npos]) {
                    dsu.merge(pos, npos, vec[pos]);
                }
            }

            std::cout << dsu.siz[pos] - 1 << "\n";
            l = dsu.siz[pos] - 1;
        } else {
            int x, y;
            std::cin >> x >> y;
            x ^= l, y ^= l;
            x--, y--;
            int pos = x * m + y;
            dsu.find(pos);
            std::cout << std::max(0LL, dsu.g[pos] - vec[pos]) << "\n";
            l = std::max(0LL, dsu.g[pos] - vec[pos]);
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
