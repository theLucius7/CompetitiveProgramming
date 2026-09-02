#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> suf(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = suf[i + 1] + a[i];
    }

    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        // std::cout << suf[i + 1] << " " << a[i] << "\n";
        sum += suf[i + 1] - (n - i - 1) * a[i];
    }
    std::cout << sum << "\n";
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
