#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(M);
    for (int i = 0; i < M; i++) {
        std::cin >> A[i];
    }

    // std::cout << (1 << (M - 1)) << "\n";

    int mx = 0;
    int cnt = 0;
    for (int i = M - 1, base = (1LL << (M - 1)); i >= 0; i--, base >>= 1) {
        cnt = cnt * 2 + A[i];
        mx = std::max(mx, (cnt + N - 1) / N * base);
    }
    std::cout << mx << "\n";
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
