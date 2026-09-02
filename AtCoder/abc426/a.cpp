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

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::map<std::string, int> map;
    map["Ocelot"] = 0, map["Serval"] = 1, map["Lynx"] = 2;

    std::string X, Y;
    std::cin >> X >> Y;

    std::cout << (map[X] >= map[Y] ? "Yes" : "No") << "\n";

    return 0;
}
