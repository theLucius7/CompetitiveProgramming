#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int N, M;
    std::cin >> N >> M;

    if (N % 2 == 1 && M % 2 == 1) {
        std::cout << N * M / 2 + 1 << "\n";
    } else if (N % 2 == 1 || M % 2 == 1) {
        std::cout << N * M / 2 << "\n";
    } else {
        std::cout << std::max((N / 2 - 1) * M, (M / 2 - 1) * N) << "\n";
    }
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
