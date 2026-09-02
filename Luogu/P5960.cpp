#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<std::pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int x, y, w;
        std::cin >> x >> y >> w;
        x--, y--;
        adj[y].push_back({x, w});
    }

    std::vector<int> ans(n, 0);
    std::queue<int> q;
    std::vector<bool> inq(n);
    std::vector<int> cnt(n);

    for (int i = 0; i < n; i++) {
        q.push(i);
        inq[i] = true;
    }

    while (!q.empty()) {
        auto x = q.front();
        q.pop();
        inq[x] = false;

        for (auto [y, w] : adj[x]) {
            if (ans[x] + w < ans[y]) {
                ans[y] = ans[x] + w;
                if (!inq[y]) {
                    inq[y] = true;
                    cnt[y]++;

                    if (cnt[y] >= n) {
                        std::cout << "NO\n";
                        return;
                    }

                    q.push(y);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << " \n"[i == n - 1];
    }


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
