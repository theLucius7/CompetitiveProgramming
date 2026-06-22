#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int N, M, Y;
    std::cin >> N >> M >> Y;
    
    std::vector<std::vector<std::pair<int, int>>> adj(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v, T;
        std::cin >> u >> v >> T;
        u--, v--;
        adj[u].push_back({v, T});
        adj[v].push_back({u, T});
    }



    for (int i = 0; i < N; i++) {
        int X;
        std::cin >> X;
        adj[i].push_back({N, X + Y});
        adj[N].push_back({i, X});
    }

    constexpr int inf = 1E18;
    std::vector<int> dis(N + 1, inf);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
    q.push({0, 0});
    dis[0] = 0;
    while (q.size()) {
        auto [d, x] = q.top();
        q.pop();
        if (dis[x] < d) continue;
        
        for (auto [y, w] : adj[x]) {
            if (dis[y] > d + w) {
                dis[y] = d + w;
                q.push({dis[y], y});
            }
        }
    }

    for (int i = 1; i < N; i++) {
        std::cout << dis[i] << " \n"[i == N - 1];
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
