#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int N;
    std::cin >> N;

    if (N == 1) {
        std::cout << 0 << "\n";
        return;
    } else if (N == 2) {
        std::cout << 1 << "\n";
        return;
    } else if (N == 3) {
        std::cout << 2 << "\n";
        return;
    }

    int lo = 1, hi = 1E10;
    while (lo < hi) {
        int m = (lo + hi) / 2;
        if (m * m >= N) {
            hi = m;
        } else {
            lo = m + 1;
        }
    }
    // std::cout << lo << "\n";

    int ans = 2 * lo * lo - 2 * lo;
    // std::cout << lo << " " << ans << "\n";

    int d = lo * lo - N;

    if (d <= lo - 1) {
        ans -= 2 * d;
        // std::cout << "?\n";
    } else if (d == lo) {
        ans -= 1 + 2 * (lo - 1);
    } else if (d <= 2 * lo - 2) {
        ans -= 1 + 2 * (lo - 1) + (d - lo) * 2;
    } else {
        ans -= 1 + (lo - 2) * 2 + 1 + (lo - 1) * 2;
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
