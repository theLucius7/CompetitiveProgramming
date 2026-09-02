#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> L(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> L[i];
        sum += L[i];
    }

    int pre = 0;
    int ans = 1E18;
    for (int i = 0; i < n; i++) {
        pre += L[i];
        sum -= L[i];
        ans = std::min(ans, std::abs(pre - sum));
    }
    std::cout << ans << "\n";
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
