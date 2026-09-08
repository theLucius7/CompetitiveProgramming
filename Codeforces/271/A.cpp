#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int a;
    std::cin >> a;

    for (int i = a + 1; ; i++) {
        std::string s = std::to_string(i);
        std::map<char, int> cnt;
        bool ok = true;
        for (auto c : s) {
            cnt[c]++;
            if (cnt[c] > 1) {
                ok = false;
            }
        }
        if (ok) {
            std::cout << s << "\n";
            return;
        }
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