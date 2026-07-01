#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, x;
    std::cin >> n >> x;

    int lst = 0;
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        lst += a;
        lst = std::max(0LL, lst - x);
    }
    std::cout << lst << "\n";
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
