#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> adj(N);
    for (int i = 0; i < M; i++) {
        int U, V;
        std::cin >> U >> V;
        U--, V--;
        adj[U].push_back(V);
        adj[V].push_back(U);
    }

    std::vector<int> ans(N, -1);
    ans[0] = 0;
    auto dfs = [&](this auto &&self, int x) -> void {
        for (auto y : adj[x]) {
            if (ans[y] == -1) {
                ans[y] = ans[x] + 1;
                self(y);
            }
        }
    };

    dfs(0);

    for (int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
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
