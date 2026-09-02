#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> oA(N), B(N - 1);
    for (int i = 0; i < N; i++) {
        std::cin >> oA[i];
    }
    for (int i = 0; i < N - 1; i++) {
        std::cin >> B[i];
    }

    int ans = 1E18;

    int res = 0;
    auto A = oA;
    for (int i = 0; i + 1 < N; i++) {
        if ((A[i] + A[i + 1]) % M != B[i]) {
            res++;
            A[i + 1]++;
        }
    }
    ans = std::min(ans, res);

    res = 1;
    A = oA;
    A[0]++;
    for (int i = 0; i + 1 < N; i++) {
        if ((A[i] + A[i + 1]) % M != B[i]) {
            res++;
            A[i + 1]++;
        }
    }
    ans = std::min(ans, res);

    std::cout << ans << "\n";
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
