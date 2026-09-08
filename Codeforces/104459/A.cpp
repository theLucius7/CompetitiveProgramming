#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    i64 n, k;
    std::cin >> n >> k;

    for (int i = 0; i < k; i++) {
        n = (n + 1) / 2;
        if (n == 1) {
            std::cout << 1 << "\n";
            return;
        } else if (n == 0) {
            std::cout << 0 << "\n";
            return;
        }
    }

    std::cout << n << "\n";
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