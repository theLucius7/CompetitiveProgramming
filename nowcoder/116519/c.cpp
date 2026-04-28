#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    if (n == 3) {
        if (a[1] % 2 == 0) {
            std::cout << a[1] / 2 << "\n";
        } else {
            std::cout << -1 << "\n";
        }
    } else {
        bool ok = false;
        i64 ans = 0;
        for (int i = 1; i < n - 1; i++) {
            if (a[i] != 1) {
                ok = true;
            }
            ans += std::ceil(1.0 * a[i] / 2);
        }

        if (ok) {
            std::cout << ans << "\n";
        } else {
            std::cout << -1 << "\n";
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
