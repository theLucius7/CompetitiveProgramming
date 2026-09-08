#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;

using u32 = unsigned;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n;
    std::cin >> n;

    int max = 0;
    std::vector<std::vector<int>> ans(20);
    auto dfs = [&](auto self, int l, int r, int depth) {
        if (l == r) {
            return;
        }
        max = std::max(max, depth);
        int m = (l + r) / 2;
        for (int i = l; i <= m; i++) {
            ans[depth].push_back(i);
        }

        self(self, l, m, depth + 1);
        self(self, m + 1, r, depth + 1);
    };

    dfs(dfs, 1, n, 1);
    std::cout << max << "\n";

    for (int i = 1; i <= max; i++) {
        std::cout << ans[i].size() << " ";
        for (int j = 0; j < ans[i].size(); j++) {
            std::cout << ans[i][j] << " \n"[j == ans[i].size() - 1];
        }
    }

}

int main() {
    std::freopen("input.txt", "r", stdin);
    std::freopen("output.txt", "w", stdout);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}