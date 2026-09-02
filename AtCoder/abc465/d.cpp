#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int X, Y, K;
    std::cin >> X >> Y >> K;

    int cnt = 0;
    while (X != Y) {
        if (X < Y) {
            Y /= K;
        } else {
            X /= K;
        }
        cnt++;
    }

    std::cout << cnt << "\n";
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
