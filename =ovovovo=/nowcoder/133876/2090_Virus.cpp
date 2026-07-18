#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    std::string s;
    std::cin >> s;

    std::string t = "aeiou";
    if (s.size() != 8) {
        std::cout << "Well-Being\n";
        return;
    }

    if (t.find(s[0]) != std::string::npos || t.find(s[2]) != std::string::npos || t.find(s[4]) != std::string::npos || t.find(s[6]) != std::string::npos) {
        std::cout << "Well-Being\n";
        return;
    }

    if (t.find(s[1]) == std::string::npos || t.find(s[3]) == std::string::npos || t.find(s[5]) == std::string::npos || t.find(s[7]) == std::string::npos) {
        std::cout << "Well-Being\n";
        return;
    }

    std::cout << "Suspected Virus\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
