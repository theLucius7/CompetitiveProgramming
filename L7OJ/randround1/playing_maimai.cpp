#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;
using real = long double;

void solve() {
    int n, m, p, q;
    std::cin >> n >> m >> p >> q;

    std::cout << std::fixed << std::setprecision(4);
    real x = 1.L * (q - p) / q;
    // std::cout << x << "\n";
    std::cout << 101.L - 1.L * (n - m) / n * x * 50 - x * 0.5 << "%\n";
    
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
