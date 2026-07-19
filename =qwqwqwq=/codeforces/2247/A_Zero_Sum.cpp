#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        sum += a;
    }

    std::cout << (n & 1 || sum % 4 != 0? "NO" : "YES") << "\n";
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
