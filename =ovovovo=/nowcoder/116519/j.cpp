#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<std::vector<int>> g(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> g[i][j];
        }
    }

    int dx[] = {1, 1, 1, -1, -1, -1, 0, 0}, dy[] = {0, 1, -1, 0, 1, -1, 1, -1};
    std::vector<std::vector<bool>> vis(n, std::vector<bool>(n));
    std::vector<std::pair<int, int>> V;
    auto dfs = [&](auto self, int x, int y, int u) -> void {
        vis[x][y] = true;
        V.push_back({x, y});
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny] && g[nx][ny] == u) {
                self(self, nx, ny, u);
            }
        }
    };

    int cntp = 0, cntv = 0;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (!vis[x][y]) {
                V.clear();
                dfs(dfs, x, y, g[x][y]);
     
                bool okp = true, okv = true;
                for (auto [ux, uy] : V) {
                    for (int i = 0; i < 8; i++) {
                        int nx = ux + dx[i], ny = uy + dy[i];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                            if (g[nx][ny] > g[x][y]) {
                                okp = false;
                            }
                            if (g[nx][ny] < g[x][y]) {
                                okv = false;
                            }
                        }
                    }
                }
                cntp += okp;
                cntv += okv;
            }
        }
    }
    std::cout << cntp << " " << cntv << "\n";

    

    return 0;
}
