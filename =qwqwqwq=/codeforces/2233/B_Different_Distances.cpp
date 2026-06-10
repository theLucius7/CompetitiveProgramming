#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;

    if (n % 2 == 1) {
        std::cout << "1 1 2 1 2 3 1 3 2 2 3 3 ";
        for (int i = 4; i < n; i += 2) {
            std::cout << i << " " << i + 1 << " " << i << " " << i << " " << i + 1 << " " << i + 1 << " " << i << " " << i + 1 << "\n";
        }
    } else {
        for (int i = 1; i < n; i += 2) {
            std::cout << i << " " << i + 1 << " " << i << " " << i << " " << i + 1 << " " << i + 1 << " " << i << " " << i + 1 << "\n";
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
