#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int N;
    std::cin >> N;

    for (int i = 1; i <= N; i++) {
        if (i % 3 == 0) {
            std::cout << "Fizz";
        } else {
            std::cout << i;
        }
        std::cout << "\n";
        // std::cout << (i % 3 == 0 ? "Fizz" : )
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
