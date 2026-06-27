#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int S1, S2;
    std::cin >> S1 >> S2;


    std::cout << std::fixed << std::setprecision(1);
    if (S2 < 45) {
        std::cout <<  0.0 << "\n";
        return;
    }

    int S = (6 * S1 + 4 * S2 + 9) / 10;
    if (S < 60) {
        std::cout << 0.0 << "\n";
    } else if (S < 95) {
        std::cout << 5 - 0.1 * (95 - S) << "\n"; 
    } else {
        std::cout << 5.0 << "\n";
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
