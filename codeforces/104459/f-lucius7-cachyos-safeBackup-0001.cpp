#include <bits/stdc++.h>

#define int long long

using i64 = long long;

void solve() {
    int k;
    std::string s;
    std::cin >> k >> s;

    int n, m;
    std::cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
    }

    if (s[(m - (n - 1) + 1) % k] == '1') {
        std::cout << 2 << "\n";
    } else {
        std::cout << 1 << "\n";
    }
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