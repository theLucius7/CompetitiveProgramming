#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, x, y, z;
    std::cin >> n >> x >> y >> z;

    std::cout << std::min((n + (x + y - 1)) / (x + y), (n + 10 * y * z + x + 10 * y - 1) / (x + 10 * y)) << "\n";
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
