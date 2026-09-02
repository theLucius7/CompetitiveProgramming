#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    std::vector<int> X(N);
    for (int i = 0; i < N; i++) {
        std::cin >> X[i];
    }
    std::vector<int> Y(N + 1);
    for (int i = 1; i < N; i++) {
        std::cin >> Y[i];
    }

    std::vector dp(N, std::vector<int>(2));
    for (int i = 0; i < N; i++) {
        if (i == 0) {
            if (S[i] == 'S') {
                dp[i][0] = 0;
                dp[i][1] = -X[i];
            } else {
                dp[i][1] = 0;
                dp[i][0] = -X[i];
            }
        } else {
            if (S[i] == 'S') {
                dp[i][0] = std::max(dp[i - 1][1] + Y[i], dp[i - 1][0]);
                dp[i][1] = std::max(dp[i - 1][0], dp[i - 1][1]) - X[i];
            } else {
                dp[i][1] = std::max(dp[i - 1][0], dp[i - 1][1]);
                dp[i][0] = std::max(dp[i - 1][1] + Y[i], dp[i - 1][0]) - X[i];
            }
        }
    }
    std::cout << std::max(dp[N - 1][0], dp[N - 1][1]) << "\n";
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
