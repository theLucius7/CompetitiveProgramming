#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int H, W, Q;
    std::cin >> H >> W >> Q;

    std::vector<std::tuple<int, int, char>> qry(Q);
    for (int i = 0; i < Q; i++) {
        int R, C;
        char X;
        std::cin >> R >> C >> X;
        R--, C--;
        qry[i] = {R, C, X};
    }

    std::vector<int> lst(H, -1);
    std::vector g(H, std::vector<char>(W, 'A'));
    for (int i = Q - 1; i >= 0; i--) {
        auto [R, C, X] = qry[i];
        for (int x = R; x >= 0; x--) {
            if (C <= lst[x]) {
                break;
            }

            for (int y = lst[x] + 1; y <= C; y++) {
                g[x][y] = X;
            }
            lst[x] = C;
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            std::cout << g[i][j];
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
