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

    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }

    DSU dsu(n + m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '=') {
                dsu.merge(i, n + j);
            }
        }
    }

    std::vector<std::vector<int>> adj(n + m);
    std::vector<int> in(n + m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '<') {
                adj[dsu.find(i)].push_back(dsu.find(n + j));
                in[dsu.find(n + j)]++;
            } else if (s[i][j] == '>') {
                adj[dsu.find(n + j)].push_back(dsu.find(i));
                in[dsu.find(i)]++;
            }
        }
    }

    std::vector<bool> vis(n + m);
    std::queue<int> q;
    for (int i = 0; i < n + m; i++) {
        int ni = dsu.find(i);
        if (in[ni] == 0 && !vis[ni]) {
            q.push(ni);
            vis[ni] = true;
        }
    }
    std::vector<int> dp(n + m, 1);
    while (!q.empty()) {
        auto x = q.front();
        q.pop();
        for (auto y : adj[x]) {
            dp[y] = std::max(dp[y], dp[x] + 1);
            if (--in[y] == 0) {
                q.push(y);
            }
        }
    }

    for (int i = 0; i < n + m; i++) {
        int ni = dsu.find(i);
        if (in[ni] != 0) {
            std::cout << "No\n";
            return;
        }
    }
    std::cout << "Yes\n";

    for (int i = 0; i < n; i++) {
        std::cout << dp[dsu.find(i)] << " \n"[i == n - 1];
    }
    for (int i = 0; i < m; i++) {
        std::cout << dp[dsu.find(n + i)] << " \n"[i == m - 1];
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
