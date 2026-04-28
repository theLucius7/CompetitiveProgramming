#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> cnt(65);
    bool ok = true;
    for (int i = 0; i < n; ++i) {
        i64 x;
        std::cin >> x;

        int hb = 63 - __builtin_clzll(x);
        cnt[hb]++;
        if (cnt[hb] > 1) {
            std::cout << "NO\n";
            return;
        }
    }
    std::cout << "YES\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}
