#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int a, b;
    std::cin >> a >> b;

    int g = std::gcd(a, b);
    a /= g, b /= g;
    std::cout << (a == 16 && b == 9 ? "Yes" : "No");
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
