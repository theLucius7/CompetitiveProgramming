#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> d(n + 1, std::vector<int>(n + 1));
    while (m--) {
        std::pair<int, int> x, y;
        std::cin >> x.first >> x.second >> y.first >> y.second;
        x.first--, x.second--, y.first--, y.second--;
        d[y.first + 1][y.second + 1]++;
        d[y.first + 1][x.second]--;
        d[x.first][y.second + 1]--;
        d[x.first][x.second]++;
    }

    std::vector<std::vector<int>> a(n + 1, std::vector<int>(n + 1));
    a[0][0] = d[0][0];
    for (int y = 1; y <= n; y++) {
        a[0][y] = d[0][y] + a[0][y - 1];
    }
    for (int x = 1; x <= n; x++) {
        a[x][0] = d[x][0] + a[x - 1][0];
    }

    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= n; y++) {
            a[x][y] = d[x][y] + a[x][y - 1] + a[x - 1][y] - a[x - 1][y - 1];
        }
    }

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            std::cout << a[x][y] << " \n"[y == n - 1];
        }
    }

	return 0;
}