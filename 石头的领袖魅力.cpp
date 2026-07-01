#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int a, b;
    std::cin >> a >> b;

    if (std::min(a, b) != 1) {
        std::cout << 1 << "\n";
    } else if (std::max(a, b) != 2) {
        std::cout << 2 << "\n";
    } else {
        std::cout << 3 << "\n";
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
