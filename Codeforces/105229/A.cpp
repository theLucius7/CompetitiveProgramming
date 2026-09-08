#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> cnt(n + 1, std::vector<int>(m + 1));
    for (int p = -n; p <= n; p++) {
        for (int q = -m; q <= m; q++) {
            if (p == 0 && q == 0) {
                continue;
            }
            for (int x = std::max({0, -p, q, q - p}); x<= std::min({n, n - p, n + q, n - p + q}); x++) {
                for (int y = std::max({0, -q, -p, -p - q}); y <= std::min({m, m - q, m - p, m - p - q}); y++) {
                    cnt[x][y]++;
                    cnt[x + p][y + q]++;
                    cnt[x - q][y + p]++;
                    cnt[x + p - q][y + q + p]++;
                }
            }
        }
    }

    for (int x = 0; x <= n; x++) {
        for (int y = 0; y <= m; y++) {
            cnt[x][y] /= 4;
            std::cout << cnt[x][y] << " \n"[y == m];
        }
    }

    return 0;
}