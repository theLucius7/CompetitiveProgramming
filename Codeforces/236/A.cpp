#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    std::string s;
    std::cin >> s;

    std::map<char, int> cnt;
    for (auto c : s) {
        cnt[c]++;
    }

    std::cout << (cnt.size() % 2 ? "IGNORE HIM!" : "CHAT WITH HER!") << "\n";
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
