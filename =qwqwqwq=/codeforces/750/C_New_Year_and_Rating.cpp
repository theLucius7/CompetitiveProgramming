#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;

    int sum = 0;
    int L = -1E18, R = 1E18;
    for (int i = 0; i < n; i++) {
        int c, d;
        std::cin >> c >> d;
        if (d == 1) {
            L = std::max(L, 1900 - sum);
        } else {
            R = std::min(R, 1899 - sum);
        }
        sum += c;
    }
    
    if (L > R) {
        std::cout << "Impossible\n";
    } else if (R == 1E18) {
        std::cout << "Infinity\n";
    } else {
        std::cout << R + sum<< "\n";
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
