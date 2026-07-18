#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, k, x;
    std::cin >> n >> k >> x;

    std::vector<int> a(n);
    int u = -1;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        if (a[i] == x) {
            u = i;
        }
    }

    auto calc = [&](std::vector<int> a) {
        std::vector<int> suf(n + 1);
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = suf[i + 1] + a[i];
        }

        int sum = 0;
        for (int i = 0; i < n - 1; i++) {
            sum += suf[i + 1] - (n - i - 1) * a[i];
        }

        
        std::cout << sum % n << "\n";
    };

    // calc(a);
    int d = x - a[k];
    for (int i = 0; i < n; i++) {
        a[i] = ((a[i] + d) % n + n) % n;
    }

    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " \n"[i == n - 1];
    }
    // calc(a);
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
