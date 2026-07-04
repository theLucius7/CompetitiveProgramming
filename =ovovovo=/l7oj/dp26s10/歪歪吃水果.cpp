#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int a, b, n, m;
    std::cin >> a >> b >> n >> m;

    std::cout << (std::min(a, b) >= (n / m) * (n / m) ? "YES" : "NO") << "\n";
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
