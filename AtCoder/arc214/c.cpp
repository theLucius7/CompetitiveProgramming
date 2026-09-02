#include <bits/stdc++.h>

using i64 = long long;

constexpr int P = 998244353;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<int> p(N);
    for (int i = 0; i < N; i++) {
        std::cin >> p[i];
    }

    i64 sum = std::accumulate(p.begin(), p.end(), 0LL);

    if (sum % 2) {
        std::cout << 0 << "\n";
        return 0;
    }

    std::vector<i64> dp(sum / 2 + 1);
    dp[0] = 1;
    for (int i = 0; i < p.size(); i++) {
        for (int j = sum / 2; j >= p[i]; j--) {
            dp[j] = (dp[j] + dp[j - p[i]]) % P;
        }
    }

    std::cout << ((((dp[sum / 2] * dp[sum / 2]) % P - 2 * dp[sum / 2]) % P + P) % P) << "\n";


    return 0;
}