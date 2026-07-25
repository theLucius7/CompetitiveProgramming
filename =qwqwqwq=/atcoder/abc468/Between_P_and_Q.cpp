#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int N;
    std::cin >> N;

    std::vector<int> P(N), Q(N);
    for (int i = 0; i < N; i++) {
        std::cin >> P[i];
    }
    for (int i = 0; i < N; i++) {
        std::cin >> Q[i];
    }

    if (P >= Q) {
        std::cout << 0 << "\n";
        return;
    }

    int cnt = 0;
    while (std::next_permutation(P.begin(), P.end())) {
        if (P == Q) {
            break;
        }
        cnt++;
    }
    std::cout << cnt << "\n";
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
