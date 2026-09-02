#include <bits/stdc++.h>

#define int long long

constexpr int inf = 1E18;

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int a, b, k;
    std::cin >> a >> b >> k;

    int cnta = 0, cntb = 0;
    for (int i = a; i; i /= k) {
        cnta++;
    }
    for (int i = b; i; i /= k) {
        cntb++;
    }

    int ans = inf;
    for (int i = 0; i <= cnta; i++) {
        if (i) {
            a /= k;
        }
        int nb = b;
        for (int j = 0; j <= cntb; j++) {
            if (j) {
                nb /= k;
            }
            ans = std::min(ans, std::abs(a - nb) + i + j);
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
