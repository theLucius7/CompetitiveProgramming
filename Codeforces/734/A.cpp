#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    int cnt = std::count(s.begin(), s.end(), 'A');
    if (cnt == n - cnt) {
        std::cout << "Friendship\n";
    } else if (cnt > n - cnt) {
        std::cout << "Anton\n";
    } else {
        std::cout << "Danik\n";
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