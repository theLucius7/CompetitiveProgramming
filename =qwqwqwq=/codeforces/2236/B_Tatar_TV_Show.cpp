#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '1') {
            if (i - k >= 0) {
                s[i - k] = (s[i - k] == '0' ? '1' : '0');
            } else {
                std::cout << "NO\n";
                return;
            }
        }
    }
    std::cout << "YES\n";
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
