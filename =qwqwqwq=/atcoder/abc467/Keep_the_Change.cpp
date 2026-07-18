#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        int A, B;
        std::string s;
        std::cin >> A >> B >> s;
        if (s == "keep") {
            sum += B - A;
        }
    }
    std::cout << sum << "\n";
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
