#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int H, W, K;
    std::cin >> H >> W >> K;

    std::vector<std::string> s(H);
    for (int i = 0; i < H; i++) {
        std::cin >> s[i];
    }

    std::vector<bool> fc(H), fr(W);
    for (int i = 0; i < H; i++) {
        bool ok = true;
        for (int j = 0; j < W; j++) {
            if (s[i][j] == '#') {
                ok = false;
                break;
            }
        }
        fc[i] = ok;
    }

    for (int j = 0; j < W; j++) {
        bool ok = true;
        for (int i = 0; i < H; i++) {
            if (s[i][j] == '#') {
                ok = false;
                break;
            }
        }
        fr[j] = ok;
    }

    std::vector<int> dist(H * W, -1);
    std::queue<std::pair<int, int>> q;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (fc[i] && fr[j]) {
                q.push({i, j});
                dist[W * i + j] = 0;
            }
        }
    }

    int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && dist[nx * W + ny] == -1 && s[nx][ny] == '.') {
                q.push({nx, ny});
                dist[nx * W + ny] = dist[x * W + y] + 1;
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (s[i][j] == '.' && dist[i * W + j] != -1 && dist[i * W + j] <= K) {
                cnt++;
            }
        }
    }
    std::cout << cnt << "\n";

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
