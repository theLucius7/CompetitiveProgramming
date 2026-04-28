#include <bits/stdc++.h>

using i64 = long long;

using i128 = __int128;
 
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

i128 power(i128 a, i128 b) {
    i128 res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}

void solve() {
    int n, k;
    std::cin >> n >> k;

    int cnt1 = __builtin_popcount(n), cnt0 = k - cnt1;
    std::cout << power(4, cnt0) * power(12, cnt1) << "\n";
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
