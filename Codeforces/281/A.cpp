#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    std::string s;
    std::cin >> s;

    if (std::islower(s[0])) {
        std::cout << (char)std::toupper(s[0]);
    } else {
        std::cout << s[0];
    }
    for (int i = 1; i < s.size(); i++) {
        std::cout << s[i];
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
