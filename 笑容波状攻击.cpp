#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    std::string s;
    std::cin >> s;

    int cnt0 = 0, cnt1 = 0;
    for (int l = 0, r = 0; l < s.size(); ) {
        while (r < s.size()) {
            if (s[r] == s[l]) {
                r++;
            }
        }

        if (s[l] == '0') {

        } else {
            
        }
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
