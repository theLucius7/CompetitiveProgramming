#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, H, M;
    std::cin >> N >> H >> M;

    std::vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i] >> B[i];
    }

    std::vector<int> dp(H + 1, -1);
    dp[H] = M;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        std::vector<int> ndp(H + 1, -1);
        for (int j = 0; j <= H; j++) {
            if (dp[j] >= 0) {
                if (j >= A[i]) {
                    ndp[j - A[i]] = std::max(ndp[j - A[i]], dp[j]);
                }
                if (dp[j] >= B[i]) {
                    ndp[j] = std::max(ndp[j], dp[j] - B[i]);
                }
            }
        }
        dp = std::move(ndp);

        if (std::count(dp.begin(), dp.end(), -1) != H + 1) {
            ans = i + 1;
        }
    }
    std::cout << ans << "\n";

    return 0;
}