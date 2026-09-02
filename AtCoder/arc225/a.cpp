#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        for (int i = 0; i < n; i++) {
            int a;
            std::cin >> a;

            if (a == 1) {
                a = 3;
            } else if (a == 2) {
                a = 1;
            } else if (a == 3) {
                a = 4;
            } else {
                a = 2;
            }
            std::cout << a << " \n"[i == n - 1];
        }
    }
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
