#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    std::string s;
    std::cin >> s;

    int n = s.size();

    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        int l = i, r = i;
        int d = 0;
        while (l >= 0 && r < n) {
            if (s[l] != s[r]) {
                d++;
                if (d > 1) {
                    break;
                }
            }

            ans++;
            l--;
            r++;
        }
    }

    for (int i = 0; i + 1 < s.size(); i++) {
        int l = i, r = i + 1;
        int d = 0;
        while (l >= 0 && r < n) {
            if (s[l] != s[r]) {
                d++;
                if (d > 1) {
                    break;
                }
            }

            ans++;
            l--;
            r++;
        }
    }

    std::cout << ans << "\n";
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
