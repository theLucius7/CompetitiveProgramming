#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int K;
    std::cin >> K;

    for (int i = 1; ; i++) {
        int x = i * K;
        std::string s = std::to_string(x);

        if (s.find("00") != std::string::npos) {
            std::cout << s << "\n";
            return;
        }
    }
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
