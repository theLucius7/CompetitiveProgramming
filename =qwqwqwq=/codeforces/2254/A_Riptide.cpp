#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    std::vector<int> a(3);
    for (int i = 0; i < 3; i++) {
        std::cin >> a[i];
    }

    for (int ans = 0; ; ans++) {
        std::sort(a.begin(), a.end());
        if (a[0] == a[1] || a[1] == a[2]) {
            std::cout << ans << "\n";
            return;
        }
        a[2]--;
        a[0]++;
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
