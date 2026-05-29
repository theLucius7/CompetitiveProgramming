#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a, b, c;
    std::cin >> a >> b >> c;

    if (a == b || b == c || a == c) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }

    return 0;
}