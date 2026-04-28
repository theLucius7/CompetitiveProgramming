#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    i64 res = 1;
    while(n) {
        int x = n % 10;
        res *= 1LL * (x + 2) * (x + 1) / 2;
        n /= 10;
    }
    std::cout << res << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }


    return 0;
}