#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    i64 x = 1LL * n * (1LL << (int)(std::log2(n) + 1)), y = x + n;
    std::cout << x << " " << y << "\n";
    // std::cout << (x ^ y) << "\n";
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