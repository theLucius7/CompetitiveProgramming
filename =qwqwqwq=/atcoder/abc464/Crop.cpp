#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int H, W;
    std::cin >> H >> W;

    std::vector<std::string> S(H);
    for (int i = 0; i < H; i++) {
        std::cin >> S[i];
    }

    int xmin = 1E9, xmax = -1, ymin = 1E9, ymax = -1;
    for (int x = 0; x < H; x++) {
        for (int y = 0; y < W; y++) {
            if (S[x][y] == '#') {
                xmin = std::min(xmin, x);
                xmax = std::max(xmax, x);
                ymin = std::min(ymin, y);
                ymax = std::max(ymax, y);
            }
        }
    }

    for (int x = xmin; x <= xmax; x++) {
        for (int y = ymin; y <= ymax; y++) {
            std::cout << S[x][y];
        }
        std::cout << "\n";
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
