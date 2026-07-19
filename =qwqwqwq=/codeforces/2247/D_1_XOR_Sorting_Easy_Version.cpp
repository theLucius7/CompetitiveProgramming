#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    constexpr int inf = 1E18;
    for (int k = 0; ; k++) {
        int len = (1 << k);

        bool ok = true;
        int lsmx = -inf, lsmn = inf;
        int mn = inf, mx = -inf;
        for (int i = 0; i <= n; i++) {
            if (i % len == 0 || i == n) {
                if (mx < lsmx || mn < lsmx) {
                    ok = false;
                    // std::cout << i << "? ";
                    break;
                }
                lsmx = mx;
                lsmn = mn;
                mn = inf, mx = -inf;
            }
            mn = std::min(mn, a[i]);
            mx = std::max(mx, a[i]);
        }

        if (ok) {
            std::cout << len / 2 << "\n";
            return;
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
