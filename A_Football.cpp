#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    std::string s;
    std::cin >> s;
    
    for (int l = 0, r = 0; l < s.size(); l = r) {
        while (r < s.size() && s[l] == s[r]) {
            r++;
        }

        if (r - l >= 7) {
            std::cout << "YES\n";
            return;
        }
    }

    std::cout << "NO\n";
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
