#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    i64 a, b, k;
    std::cin >> a >> b >> k;

    if (a <= k && b <= k) {
        std::cout << "1\n";
        return;
    }

    i64 g = std::gcd(a, b);
    i64 x = a / g, y = b / g;
    if (x <= k && y <= k) {
        std::cout << "1\n";
        return;
    }
    std::cout << "2\n";
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
