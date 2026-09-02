#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int A, B;
    std::cin >> A >> B;

    if (A + B == 9 || A * B == 9 || A == B * 9 || A - B == 9) {
        std::cout << "Nine\n";
    } else {
        std::cout << "Nein\n";
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
