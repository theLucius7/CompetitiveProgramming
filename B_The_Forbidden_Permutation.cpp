#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, m, d;
    std::cin >> n >> m >> d;

    std::vector<int> pos(n + 1);
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        pos[a] = i;
    }

    std::vector<int> a(m);
    for (int i = 0; i < m; i++) {
        std::cin >> a[i];
    }

    int ans = 1E18;
    for (int i = 1; i < m; i++) {
        int u = pos[a[i]] - pos[a[i - 1]];
        if (u > d || u < 0) {
            std::cout << 0 << "\n";
            return;
        } else {
            
            ans = std::min({ans, u});
            if (d < n - 1) {
                ans = std::min(ans, d - u + 1);
            }
        }
    }

    std::cout << ans << "\n";

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
