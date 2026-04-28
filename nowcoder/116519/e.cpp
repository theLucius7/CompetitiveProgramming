#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

std::ostream &operator<<(std::ostream &os, i128 n) {
    if (n == 0) {
        return os << 0;
    }
    std::string s;
    while (n > 0) {
        s += char('0' + n % 10);
        n /= 10;
    }
    std::reverse(s.begin(), s.end());
    return os << s;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        if (a[i] == 0) {
            std::cout << 0 << "\n";
            return 0;
        }
    }

    i128 res = 1;
    for (int i = 0; i < n; i++) {
        res *= (i128)a[i];
        if (res > 1000000000000000000) {
            std::cout << -1 << "\n";
            return 0;
        }
    }
    std::cout << res << "\n";

    return 0;
}
