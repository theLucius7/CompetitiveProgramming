#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int m, n;
    std::cin >> m >> n;

    i64 u = 1;
    int cnt = 0;
    while (u < m) {
        u *= (n + 1);
        cnt++;
    }
    std::cout << cnt << "\n";

    return 0;
}