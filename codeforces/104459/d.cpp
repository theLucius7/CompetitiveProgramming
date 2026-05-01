#include <bits/stdc++.h>

#define int long long

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int p = std::accumulate(a.begin(), a.end(), 0LL) / n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += std::max(0LL, a[i] - p);
    }

    std::cout << ans << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }


    return 0;
}