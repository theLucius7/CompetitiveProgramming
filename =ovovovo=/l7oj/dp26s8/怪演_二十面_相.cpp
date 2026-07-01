#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    std::string s;
    std::cin >> s;

    int cntR = 0, cntB = 0;
    int ans = 1;
    for (int i = 0; i <= s.size(); i++) {
        if (i == s.size()) {
            ans = std::max(ans, cntR + cntB);
        } else if (s[i] == 'R') {
            if (cntB) {
                cntB--;
                cntR++;
            } else {
                cntR++;
            }
        } else if (s[i] == 'B') {
            if (cntR) {
                cntR--;
                cntB++;
            } else {
                cntB++;
            }
        } else {
            ans = std::max(ans, cntR + cntB);
            cntR = 0;
            cntB = 0;
        }
    }

    std::cout << ans << "\n";
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
