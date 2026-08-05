#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    std::string s;
    std::cin >> s;

    std::string t = "hello";
    int id = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == t[id]) {
            id++;
            if (id == t.size()) {
                std::cout << "YES\n";
                return;
            }
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
