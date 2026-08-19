#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<std::vector<std::pair<int, int>>> pos(n); 
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            std::cin >> x;
            x--;
            pos[x].push_back({j, i});
        }
    }
    
    std::vector<std::vector<std::pair<int, int>>> adj(n);
    for (int i = 0; i < n; i++) {
        if (pos[i].size() != 2) {
            std::cout << -1 << "\n";
            return;
        }
        auto [u1, v1] = pos[i][0];
        auto [u2, v2] = pos[i][1];
        if (v1 == v2) {
            adj[u1].push_back({u2, 1});
            adj[u2].push_back({u1, 1});
        } else {
            adj[u1].push_back({u2, 0});
            adj[u2].push_back({u1, 0});
        }
    }

    std::vector<int> col(n, -1);
    std::vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (col[i] != -1) {
            continue;
        }

        std::vector<int> comps;
        auto dfs = [&](this auto &&self, int x, int c) -> void {
            comps.push_back(x);
            col[x] = c;
            for (auto [y, w] : adj[x]) {
                if (col[y] == -1) {
                    self(y, c ^ w);
                } else if (col[y] != c ^ w) {
                    std::cout << -1 << "\n";
                    return;
                }
            }
        };
        dfs(i, 0);

        std::vector<int> u, v;
        for (auto x : comps) {
            if (col[x]) {
                u.push_back(x);
            } else {
                v.push_back(x);
            }
        }
        if (u.size() > v.size()) {
            std::swap(u, v);
        }
        for (auto x : u) {
            ans.push_back(x);
        }
    }
    std::cout << ans.size() << "\n";
    std::sort(ans.begin(), ans.end());
    for (auto x : ans) {
        std::cout << x + 1 << " ";
    }
    std::cout << "\n";
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
