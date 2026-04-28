#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<std::vector<int>> a(N, std::vector<int>(N));
    
    std::array<int, 4> dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};
    int x = 0, y = 0, d = 0;
    for (int i = 1; i <= N * N; i++) {
        a[x][y] = i;
        int nx = x + dx[d], ny = y + dy[d];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N || a[nx][ny] != 0) {
            d = (d + 1) % 4;
            nx = x + dx[d];
            ny = y + dy[d];
        }

        x = nx;
        y = ny;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << std::setw(3) << a[i][j];
        }
        std::cout << "\n";
    }




    return 0;
}
