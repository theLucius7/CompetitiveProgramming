#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);

    std::vector<int> cnt(12);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        ans ^= a[i];
        for (int j = 0; j <= 10; j++) {
            if ((a[i] >> j) & 1) {
                cnt[j]++;
            }
        }
    }

    
    for (int i = 0; i <= 10; i++) {
        if (cnt[i] >= 2) {
            ans += 2 * (1 << i);
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
