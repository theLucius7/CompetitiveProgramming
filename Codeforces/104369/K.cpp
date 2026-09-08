#include <bits/stdc++.h>

using namespace std;

constexpr int N = 10;

int n, m, k, ans;
int a[N][N];
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

void dfs(int cnt) {
    ans = std::max(ans, cnt);
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= m; j ++ ) {
            if (a[i][j]) {
                // a[i][j] = 0;
                for (int K = 0; K < 4; K++) {
                    int nx = i + dx[K], ny = j + dy[K];
                    int mx = nx + dx[K], my = ny + dy[K];
                    if (mx >= 1 && mx <= n && my >= 1 && my <= m && a[nx][ny] && !a[mx][my] ) {
                        // cout << i << " " << j << endl;
                        a[nx][ny] = 0;
                        a[mx][my] = 1;
                        a[i][j] = 0;
                        dfs(cnt + 1);
                        a[nx][ny] = 1;
                        a[mx][my] = 0;
                        a[i][j] = 1;
                    }
                }
            }
        }
    }
}

void solve() {
    // int n, m, k;
    std::cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        int x, y;
        std::cin >> x >> y;
        // x--, y--;
        a[x][y] = 1;
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         std::cout << a[i][]
    //     }
    // }

    dfs(0);
    std::cout << k - ans << "\n";

    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= m; j ++ ) {
            a[i][j] = 0;
        }
    }
    ans = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T -- ) {
        solve();
    }

    return 0;
}