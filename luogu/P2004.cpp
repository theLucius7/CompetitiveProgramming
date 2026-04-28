#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1E9 + 1;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, M, C;
    std::cin >> N >> M >> C;

    std::vector<std::vector<int>> g(N, std::vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> g[i][j];
        }
    }

    std::vector<std::vector<int>> pre(N + 1, std::vector<int>(M + 1));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            pre[i + 1][j + 1] = pre[i + 1][j] + pre[i][j + 1] - pre[i][j] + g[i][j];
        }
    }

    int max = -inf;
    std::pair<int, int> ans;
    for (int i = C - 1; i < N; i++) {
        for (int j = C - 1; j < M; j++) {
            if (pre[i + 1][j + 1] - pre[i + 1][j - C + 1] - pre[i - C + 1][j + 1] + pre[i - C + 1][j - C + 1] > max) {
                max = pre[i + 1][j + 1] - pre[i + 1][j - C + 1] - pre[i - C + 1][j + 1] + pre[i - C + 1][j - C + 1];
                ans = {i - C + 2, j - C + 2};
            }
        }
    }
    std::cout << ans.first << " " << ans.second << "\n";

	return 0;
}