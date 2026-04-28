#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<int>> adj(N);
    for (int i = 0; i < N - 1; i++) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    std::unordered_map<int, int> cnt;
    std::vector<int> ans(N);
    auto dfs = [&](auto self, int x, int fa) -> void {
        cnt[A[x]]++;
        if (cnt[A[x]] == 2) {
            ans[x] = 1;
        }
        ans[x] |= ans[fa];

        for (int y : adj[x]) {
            if (y != fa) {
                self(self, y, x);
            }
        }
        cnt[A[x]]--;
        return;
    };

    dfs(dfs, 0, 0);

    for (int i = 0; i < N; i++) {
        std::cout << (ans[i] == 1 ? "Yes" : "No") << "\n";
    }



    return 0;
}
