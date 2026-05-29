#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int H, W;
    std::cin >> H >> W;

    std::vector<std::string> S(H);
    for (int i = 0; i < H; i++) {
        std::cin >> S[i];
    }

    int dx[] = {1, 1, 1, -1, -1, -1, 0, 0}, dy[] = {0, 1, -1, 0, 1, -1, 1, -1};
    std::vector<std::vector<bool>> vis(H, std::vector<bool>(W));
    auto dfs = [&](auto self, int x, int y) -> void {
        vis[x][y] = true;
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && S[nx][ny] == '#' && !vis[nx][ny]) {
                self(self, nx, ny);
            }
        }
    };

    int cnt = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '#' && !vis[i][j]) {
                dfs(dfs, i, j);
                cnt++;
            }
        }
    }
    std::cout << cnt << "\n";

    return 0;
}
