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

    for (int l = 0, r = 0; l < n; ) {
        while (r <= n) {
            if (r == n || a[r] != a[l]) {
                if (a[l] == 1 && r - l != 2) {
                    std::cout << "Alice\n";
                    return;
                }
                l = r;
            }
            r++;
        }
    }
    std::cout << "Bob\n";
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
