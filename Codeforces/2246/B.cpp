#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;

    if (n == 1) {
        std::cout << 1 << "\n";    
    } else if (n == 2) {
        std::cout << -1 << "\n";
    } else {
        std::cout << 1 << " " << 2 << " ";
        for (int i = 3, x = 3; i <= n; i++, x *= 2) {
            std::cout << x << " \n"[i == n];
        }
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