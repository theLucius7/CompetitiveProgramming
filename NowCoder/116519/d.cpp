#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> g(n);
    for (int i = 0; i < n; i++) {
        std::cin >> g[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '-') {
                std::cout << g[i][j];
            } else {
                std::cout << ((i + j) % 2 == 0 ? "B" : "W");
            }

            if (j == m - 1) {
                std::cout << "\n";
            }
        }
    }

    return 0;
}
