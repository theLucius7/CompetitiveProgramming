#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, Q;
    if (!(std::cin >> N >> Q)) return 0;

    std::vector<int> W(N), V(N);
    for (int i = 0; i < N; i++) {
        std::cin >> W[i] >> V[i];
    }

    for (int qi = 0; qi < Q; qi++) {
        int L, R, C;
        std::cin >> L >> R >> C;
        --L, --R; // convert to 0-based

        std::vector<i64> dp(C + 1, 0);
        for (int i = L; i <= R; i++) {
            int w = W[i];
            int v = V[i];
            if (w > C) continue;
            for (int c = C; c >= w; c--) {
                dp[c] = std::max(dp[c], dp[c - w] + (i64)v);
            }
        }
        std::cout << dp[C] << "\n";
    }

    return 0;
}
