#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    i64 n; 
    std::cin >> n;

    i64 add = 0, l = 1, h = 3;
    while (n / h) {
        add += (n / h) * l;
        if (l > ULLONG_MAX / 3 || h > ULLONG_MAX / 3) {
            break;
        }
        l *= 3;
        h *= 3;
    }

    std::cout << 3ull * n + add << '\n';
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