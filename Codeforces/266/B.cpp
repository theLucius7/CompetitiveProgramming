#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, t;
    std::cin >> n >> t;

    std::string s;
    std::cin >> s;

    for (int _ = 0; _ < t; _++) {
        auto ns = s;
        for (int i = 0; i + 1 < n; i++) {
            if (s[i] == 'B' && s[i + 1] == 'G') {
                std::swap(ns[i], ns[i + 1]);
            }
        }
        s = std::move(ns);
    }
    std::cout << s << "\n";
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
