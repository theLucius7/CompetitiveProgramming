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
    std::string s, t;
    std::cin >> s >> t;

    if (s[0] == t[0]) {
        std::cout << "YES\n";
        std::cout << s[0] << "*\n";
    } else if (s.back() == t.back()) {
        std::cout << "YES\n";
        std::cout << "*" << s.back() << "\n";
    } else {
        for (int i = 0; i < s.size() - 1; i++) {
            if (t.find(s.substr(i, 2)) != std::string::npos) {
                std::cout << "YES\n";
                std::cout << "*" << s.substr(i, 2) << "*\n";
                return;
            }
        }
        std::cout << "NO\n";
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
