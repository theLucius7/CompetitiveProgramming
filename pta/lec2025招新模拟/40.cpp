#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int h, m;
    char c;
    std::cin >> h >> c >> m;

    if ((0 <= h && h < 12) || (h == 12 && m == 0)) {
        std::cout << "Only " << std::setfill('0') << std::setw(2) << h << ":" << std::setw(2) << m << ".  Too early to Dang.";
    } else {
        for (int i = 0; i < h - 12 + (m != 0); i++) {
            std::cout << "Dang";
        }
    }

    return 0;
}