#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1E9 + 10;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M, L;
    std::cin >> N >> M >> L;

    std::vector<int> a(N);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }

    std::vector<std::vector<int>> g(L);
    for (int i = 0; i < N; i++) {
        g[i % L].push_back(a[i]);
    }

    std::vector<std::vector<int>> cost(L, std::vector<int>(M));
    for (int i = 0; i < L; i++) {
        std::sort(g[i].begin(), g[i].end());
        i64 sum = accumulate(g[i].begin(), g[i].end(), 0LL);

        int p = 0;
        for (int x = 0; x < M; x++) {
            while (p < g[i].size() && g[i][p] <= x) {
                p++;
            }
            i64 c = 1LL * x * g[i].size() - sum + 1LL * M * (g[i].size() - p);
            cost[i][x] = c;
        }
    }

    std::vector<int> dp(M, inf);
    dp[0] = 0;
    for (int i = 0; i < L; i++) {
        auto &nc = cost[i];

        std::vector<int> ndp(M, inf);
        for (int r = 0; r < M; r++) {
            if (dp[r] != inf) {
                for (int x = 0; x < M; x++) {
                    ndp[(r + x) % M] = std::min(ndp[(r + x) % M], dp[r] + nc[x]);
                }
            }
        }
        dp.swap(ndp);
    }
    std::cout << dp[0] << "\n";
    
    return 0;
}
