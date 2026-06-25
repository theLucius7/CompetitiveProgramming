#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, m;
    std::cin >> n >> m;

    int last = -1;
    bool ok = true;
    for (int i = 0; i < n; i++) {
        int nx = 1E18;
        for (int j = 0; j < m; j++) {
            int a;
            std::cin >> a;
            if (a > last) {
                nx = std::min(nx, a);
            }
        }

        if (nx == 1E18) {
            ok = false;
        }

        last = nx;
    }

    if (!ok) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n";   
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
