#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1E8 + 1;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::vector<int> deg(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        deg[x]++, deg[y]++;
    }

    if (n == 1) {
        std::cout << a[0] << "\n";
        return 0;
    }

    int max = 1;
    int max0 = 1, max1 = 1;
    for (int i = 0; i < n; i++) {
        if (deg[i] != 1) {
            max = std::max(max, a[i]);
        } else {
            if (a[i] >= max0) {
                max1 = max0;
                max0 = a[i];
            } else {
                max0 = std::max(max0, a[i]);
            }
        }
    }
    std::cout << std::max(max, max1) << "\n";

    return 0;
}