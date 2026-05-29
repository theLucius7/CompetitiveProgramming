#include <bits/stdc++.h>

using i64 = long long;
using namespace std;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> c(n);
    std::vector<std::vector<int>> pos(55);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> c[i];
        pos[c[i]].push_back(i);
        cnt = std::max(cnt, c[i]);
    }

    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
    }

    k = std::min(k, cnt + 1);


    for (int col = 1; col <= cnt; col++) {
        if (pos[col].empty()) {
            continue;
        }

        for (int u = 0; u < 17; u++) {
            std::queue<int> q;
            std::vector<int> dis(n);
            std::vector<bool> ok(n);
            for (auto x : pos[col]) {
                if ((x >> u) & 1) {
                    q.push(x);
                    dis[x] = 1;
                } else {
                    ok[x] = true;
                }
            }


            while (!q.empty()) {
                int x = q.front();
                q.pop();

                if (dis[x] > k - 1) {
                    break;
                }

                for (auto y : adj[x]) {
                    if (!dis[y]) {
                        if (ok[y]) {
                            std::cout << "NO\n";
                            return;
                        }
                        q.push(y);
                        dis[y] = dis[x] + 1;
                    }

                }
            }
        }


        for (int u = 0; u < 17; u++) {
            std::queue<int> q;
            std::vector<int> dis(n);
            std::vector<bool> ok(n);
            for (auto x : pos[col]) {
                if ((x >> u) & 1) {
                    ok[x] = true;
                } else {
                    q.push(x);
                    dis[x] = 1;
                }
            }


            while (!q.empty()) {
                int x = q.front();
                q.pop();

                if (dis[x] > k - 1) {
                    break;
                }

                for (auto y : adj[x]) {
                    if (!dis[y]) {
                        if (ok[y]) {
                            std::cout << "NO\n";
                            return;
                        }
                        q.push(y);
                        dis[y] = dis[x] + 1;
                    }

                }
            }
        }
    }

    std::cout << "YES\n";

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    t = 1;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
