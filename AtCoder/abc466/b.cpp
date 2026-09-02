#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> mx(M, -1);
    for (int i = 0; i < N; i++) {
        int C, S;
        std::cin >> C >> S;
        C--;
        mx[C] = std::max(mx[C], S);
    }
    for (int i = 0; i < M; i++) {
        std::cout << mx[i] << " \n"[i == M - 1];
    }
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
