#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;

    std::map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        cnt[a]++;
    }
    std::cout << (cnt.size() > 3 ? "NO" : "YES") << "\n";
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
