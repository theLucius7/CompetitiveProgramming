#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;

    int x = 0, y = 0, z = 0;
    for (int i = 0; i < n; i++) {
        int nx, ny, nz;
        std::cin >> nx >> ny >> nz;

        x += nx;
        y += ny;
        z += nz;
    }

    if (x == 0 && y == 0 && z == 0) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
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
