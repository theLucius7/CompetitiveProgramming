#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M, L;
    i64 S, T;
    std::cin >> N >> M >> L >> S >> T;

    std::vector<std::vector<std::pair<int, int>>> adj(N);
    for (int i = 0; i < M; i++) {
        int x, y, c;
        std::cin >> x >> y >> c;
        x--, y--;
        adj[x].emplace_back(y, c);
    }

    std::vector<std::set<i64>> dp(N);
    dp[0].insert(0);
    for (int i = 0; i < L; i++) {
        std::vector<std::set<i64>> ndp(N);
        for (int x = 0; x < N; x++) {            
            for (auto [y, c] : adj[x]) {
                for (auto v : dp[x]) {
                    if (v + c <= T) {
                        ndp[y].insert(v + c);
                    }
                }
            }
        }
        dp = std::move(ndp);
    }

    std::vector<int> ans;
    for (int i = 0; i < N; i++) {
        for (auto v : dp[i]) {
            if (v >= S && v <= T) {
                ans.push_back(i + 1);
                break;
            }
        }
    }

    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i] << " \n"[i == ans.size() - 1];
    }

    return 0;
}