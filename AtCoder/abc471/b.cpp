#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;

    std::map<std::string, int> cnt;
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < s.size(); j++) {
            s[j] = std::tolower(s[j]);
        }
        // std::cout << s << "\n";
        cnt[s]++;
    }

    int max = 0;
    for (auto [_, t] : cnt) {
        max = std::max(max, t);
    }

    // auto it = *cnt.rbegin();

    std::cout << max << "\n";
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
