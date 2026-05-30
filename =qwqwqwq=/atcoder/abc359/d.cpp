#include <bits/stdc++.h>

using i64 = long long;

constexpr int P = 998244353;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N, K;
    std::cin >> N >> K;

    std::string S;
    std::cin >> S;

    std::vector<std::map<std::string, i64>> dp(N + 1);
    dp[0][""] = 1;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '?') {
            for (auto [dpk, v] : dp[i]) {
                std::string k = dpk;
                k.push_back('A');
                if (k.size() > K) {
                    k.erase(k.begin());
                }
                std::string nk = k;
                std::reverse(nk.begin(), nk.end());
                if (k.size() < K || (k.size() == K && k != nk)) {
                    dp[i + 1][k] += v; 
                    dp[i + 1][k] %= P;
                }
            }
            for (auto [dpk, v] : dp[i]) {
                std::string k = dpk;
                k.push_back('B');
                if (k.size() > K) {
                    k.erase(k.begin());
                }
                std::string nk = k;
                std::reverse(nk.begin(), nk.end());
                if (k.size() < K || (k.size() == K && k != nk)) {
                    dp[i + 1][k] += v; 
                    dp[i + 1][k] %= P;
                }
            }

        } else if (S[i] == 'A') {
            for (auto [dpk, v] : dp[i]) {
                std::string k = dpk;
                k.push_back('A');
                if (k.size() > K) {
                    k.erase(k.begin());
                }
                std::string nk = k;
                std::reverse(nk.begin(), nk.end());
                if (k.size() < K || (k.size() == K && k != nk)) {
                    dp[i + 1][k] += v; 
                    dp[i + 1][k] %= P;
                }
            }
        } else {
            for (auto [dpk, v] : dp[i]) {
                std::string k = dpk;
                k.push_back('B');
                if (k.size() > K) {
                    k.erase(k.begin());
                }
                std::string nk = k;
                std::reverse(nk.begin(), nk.end());
                if (k.size() < K || (k.size() == K && k != nk)) {
                    dp[i + 1][k] += v; 
                    dp[i + 1][k] %= P;
                }
            }
        }
    }

    i64 ans = 0;
    for (auto [k, v] : dp[N]) {
        ans += v;
        ans %= P;
    }

    std::cout << ans << "\n";

    return 0;
}
