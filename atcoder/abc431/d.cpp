#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 inf = 1E18 + 1;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    std::cin >> N;

    std::vector<i64> W(N), H(N), B(N);
    i64 sumH = 0, sumB = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> W[i] >> H[i] >> B[i];
        sumH += W[i];
        sumB += B[i];
    }

    std::vector<std::pair<i64, i64>> V;
    i64 sum = 0;
    for (int i = 0; i < N; i++) {
    	i64 d = H[i] - B[i];
    	if (d > 0) {
    		V.emplace_back(W[i], d);
    		sum += W[i];
    	}
    }

    i64 C = std::min(sum, sumH / 2);
    std::vector<i64> dp(C + 1, -inf);
    dp[0] = 0;
    for (auto [w, v] : V) {
        for (i64 i = C; i >= w; i--) {
            if (dp[i - w] != -inf) {
                dp[i] = std::max(dp[i], dp[i - w] + v);
            }
        }
    }

    i64 max = 0;
    for (i64 i = 0; i <= C; i++) {
        max = std::max(max, dp[i]);
    }

    std::cout << (sumB + max) << "\n";
    return 0;
}
