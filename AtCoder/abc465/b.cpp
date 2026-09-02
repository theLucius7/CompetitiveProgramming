#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int X, Y, L, R, A, B;
    std::cin >> X >> Y >> L >> R >> A >> B;

    int sum = 0;
    for (int i = A; i < B; i++) {
        if (i >= L && i < R) {
            sum += X;
        } else {
            sum += Y;
        }
    }
    std::cout << sum << "\n";
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
