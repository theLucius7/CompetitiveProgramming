#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    int a = std::ceil(std::sqrt(n)), b = std::ceil(n * 1.0 / a);
    std::vector<std::vector<int>> g(a, std::vector<int>(b));
    int cur = 1;
    for (int i = 0; i < a; i++) {
        bool ok = false;
        for (int j = 0; j < b; j++) {
            g[i][j] = cur++;
            if (cur == n + 1) {
                ok = true;
                break;
            }
        }
        if (ok) {
            break;
        }
    }

    std::vector<std::pair<int, int>> ansa, ansb;
    
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b - 1; j++) {
            if (g[i][j] == 0 || g[i][j + 1] == 0) {
                continue;
            }
            ansa.emplace_back(g[i][j], g[i][j + 1]);
        }
    }
    for (int j = 0; j < b; j++) {
        for (int i = 0; i < a - 1; i++) {
            if (g[i][j] == 0 || g[i + 1][j] == 0) {
                continue;
            }
            ansb.emplace_back(g[i][j], g[i + 1][j]);
        }
    }

    int cnt = std::min(ansa.size(), ansb.size());

    std::cout << cnt << "\n";
    for (int i = 0; i < cnt; i++) {
        std::cout << ansa[i].first << " " << ansa[i].second << "\n";
    }
    for (int i = 0; i < cnt; i++) {
        std::cout << ansb[i].first << " " << ansb[i].second << "\n";
    }

    

    return 0;
}