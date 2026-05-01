#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;

using u32 = unsigned;

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

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int max = -1, min = n;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == a[i + 1]) {
            min = std::min(min, i);
            max = std::max(max, i);
        }
    }

    if (min >= max) {
        std::cout << 0 << "\n";
    } else {
        std::cout << std::max(1, max - min - 1) << "\n";
    }
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
