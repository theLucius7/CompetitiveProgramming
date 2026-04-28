#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    u64 n;
    std::cin >> n;

    auto ok = [&](int x) {
        if ((n >> x)) {
            return false;
        }

        for (int i = 0; i < x / 2; i++) {
            if (((n >> i) ^ (n >> (x - i - 1))) & 1) {
                return false;
            }
        }

        if ((x & 1) && ((n >> (x / 2)) & 1)) {
            return false;
        }

        return true;
    };

    for (int i = 1; i <= 60; i++) {
        if (ok(i)) {
            std::cout << "YES\n";
            return;
        }
    }
    std::cout << "NO\n";
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
