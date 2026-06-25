#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, s;
    std::cin >> n >> s;

    bool ok1 = false, ok2 = true;
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        if (a == s) {
            ok1 = true;
        }
        if (a != 0 && a != s) {
            ok2 = false;
        }
    }
    if (ok1 && ok2) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
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
