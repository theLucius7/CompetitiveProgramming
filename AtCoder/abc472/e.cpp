#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> adj(N);
    for (int i = 0; i < M; i++) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    std::vector<int> col(N, -1);
    std::vector<int> fa(N, -1);
    std::vector<int> ans;
    auto dfs = [&](this auto &&self, int x, int c) -> void {
        col[x] = c;
        for (auto y : adj[x]) {
            if (ans.size()) {
                return;
            }
            if (col[y] == -1) {
                fa[y] = x;
                self(y, c ^ 1);
            } else if (col[y] == c) {
                ans.push_back(y);
                int cur = x;
                while (cur != y) {
                    ans.push_back(cur);
                    cur = fa[cur];
                }
                return;
            }
        }
    };

    for (int i = 0; i < N; i++) {
        if (col[i] == -1) {
            dfs(i, 0);
        }
    }
    

    if (ans.empty()) {
        std::cout << "-1\n";
    } else {
        std::cout << ans.size() << "\n";
        for (int i = 0; i < ans.size(); i++) {
            std::cout << ans[i] + 1 << " \n"[i == ans.size() - 1];
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
