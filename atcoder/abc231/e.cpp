#include <bits/stdc++.h>

using i64 = long long;

using real = long double;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
    i64 X;
    std::cin >> N >> X;

    std::vector<i64> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> f(N);
    for (int i = N - 1; i >= 0; i--) {
        int cnt = X / A[i];
        f[i] = cnt;
        X -= cnt * A[i];
    }

    std::vector<std::array<int, 2>> dp(N);
    dp[0][0] = f[0];
    dp[0][1] = 1 + A[1] / A[0] - f[0];
    for (int i = 1; i < N; i++) {
        for (int t = 0; t < 1; t++) {
            if (t == 0) {
                
            } else {
                
            }
        }
    }
    std::cout << dp[N - 1][0] << "\n";

	return 0;
}