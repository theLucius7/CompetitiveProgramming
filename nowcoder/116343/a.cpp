#include <bits/stdc++.h>

using i64 = long long;

int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a, l, r;
    std::cin >> a >> l >> r;

    std::cout << std::ceil(a * 1.0 / r) << "\n";

    return 0;
}