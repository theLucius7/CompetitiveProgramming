#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, s;
    std::cin >> n >> s;

    std::vector<int> a(n);
    std::vector<int> sum(n + 1);
    std::vector<int> mx(n + 1);
    std::vector<int> ans(n + 1);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        sum[i + 1] = sum[i] + a[i];
        if (a[i] > mx[i]) {
            ans[i + 1] = i + 1;
        } else {
            ans[i + 1] = ans[i];
        }
        mx[i + 1] = std::max(mx[i], a[i]);
    }

    if (sum[n] <= s) {
        std::cout<< 0 << "\n";
        return;
    }

    for (int i = n - 1; i >= 0; i--) {
        if (sum[i + 1] <= mx[i + 1] + s) {
            std::cout << ans[i + 1] << "\n";
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
