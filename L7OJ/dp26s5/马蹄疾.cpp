#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, t, S;
    std::cin >> n >> t >> S;

    std::cout << ((S >= 0 && S <= n * ((1 << t) - 1)) ? "Yes" : "No") << "\n";
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
