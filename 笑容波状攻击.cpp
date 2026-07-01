#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    std::string s;
    std::cin >> s;

    int cnt0 = 0, cnt1 = 0;
    for (int l = 0, r = 0; l < s.size(); l = r) {
        while (r < s.size() && s[r] == s[l]) {
            r++;
        }

        int len = r - l;
        // std::cout << s[l] << " " << len << "\n";
        if (s[l] == '0') {
            cnt0 += len * (len + 1) / 2;
        } else {
            cnt1 += len * (len + 1) / 2;
        }
    }
    // std::cout << cnt0 << " " << cnt1 << "!\n";

    std::cout << 1LL * s.size() * (s.size() + 1) - cnt0 - 2 * cnt1 << "\n";
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
