#include <bits/stdc++.h>

using i64 = long long;

int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

struct State {
    int x, y, steps;
    bool flag;
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int H, W;
    std::cin >> H >> W;

    std::vector<std::string> g(H);
    for (int i = 0; i < H; i++) {
        std::cin >> g[i];
    }

    std::pair<int, int> S, G;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (g[i][j] == 'S') {
                S = {i, j};
            } else if (g[i][j] == 'G') {
                G = {i, j};
            }
        }
    }

    std::queue<State> q;
    std::vector<std::vector<std::vector<bool>>> vis;
    vis.assign(H, std::vector<std::vector<bool>>(W, std::vector<bool>(2, false)));

    q.push({S.first, S.second, 0, false});
    vis[S.first][S.second][0] = true;
    while (q.size()) {
        auto u = q.front();
        q.pop();

        if (u.x == G.first && u.y == G.second) {
            std::cout << u.steps << "\n";
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int nx = u.x + dx[i], ny = u.y + dy[i];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W) {
                if (g[nx][ny] == '?' && !vis[nx][ny][!u.flag]) {
                    q.push({nx, ny, u.steps + 1, !u.flag});
                    vis[nx][ny][!u.flag] = true;
                } else if (g[nx][ny] == 'o' && u.flag == false && !vis[nx][ny][u.flag]) {
                    q.push({nx, ny, u.steps + 1, u.flag});
                    vis[nx][ny][u.flag] = true;
                } else if (g[nx][ny] == 'x' && u.flag == true && !vis[nx][ny][u.flag]) {
                    q.push({nx, ny, u.steps + 1, u.flag});
                    vis[nx][ny][u.flag] = true;
                } else if ((g[nx][ny] == '.' || g[nx][ny] == 'G' || g[nx][ny] == 'S') && !vis[nx][ny][u.flag]) {
                    q.push({nx, ny, u.steps + 1, u.flag});
                    vis[nx][ny][u.flag] = true;
                }
            }
        }
    }
    std::cout << -1 << "\n";

    return 0;
}
