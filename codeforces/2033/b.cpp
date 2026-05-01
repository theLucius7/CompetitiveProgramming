#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> a(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> a[i][j];
        }
    }

    int cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
        int min = 0;
        for (int k = 0; k < n; k++) {
            int x = i + k, y = k;
            if (x >= n || y >= n) {
                break;
            }
            min = std::min(min, a[x][y]);
        }
        cnt += -min;
    }

    for (int i = 1; i < n; i++) {
        int min = 0;
        for (int k = 0; k < n; k++) {
            int x = k, y = i + k;
            if (x >= n || y >= n) {
                break;
            }
            min = std::min(min, a[x][y]);
        }
        cnt += -min;
    }

    std::cout << cnt << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }


	return 0;
}