#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> adj(N);
    for (int i = 0; i < M; i++) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        adj[y].push_back(x);
    }

    std::vector<bool> vis(N);
    std::vector<int> ans(N);
    auto dfs = [&](auto self, int x, int max) -> void {
        ans[x] = max;
        vis[x] = true;
        for (auto y : adj[x]) {
            if (!vis[y]) {
                self(self, y, max);
            }
        }
    };


    for (int i = N - 1; i >= 0; i--) {
        if (!vis[i]) {
            dfs(dfs, i, i);
        }
    }

    for (int i = 0; i < N; i++) {
        std::cout << ans[i] + 1 << " \n"[i == N - 1];
    }


	return 0;
}