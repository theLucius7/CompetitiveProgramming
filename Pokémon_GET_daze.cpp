#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int x, y, z;
    std::cin >> x >> y >> z;
    
    std::vector<std::vector<std::string>> s(x, std::vector<std::string>(y));
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            std::cin >> s[i][j];
        }
    }

    const int n = x + y + z;
    std::queue<std::pair<int, int>> q;
    std::vector<std::vector<int>> rel(n, std::vector<int>(n));

    auto add = [&](int u, int v) {
        if (rel[u][v] == 0) {
            rel[u][v] = 1, rel[v][u] = -1;
            q.push({u, v});
        }
    };
    add(0, x);

    auto inX = [&](int a) { // R
        return a < x;
    };
    auto inY = [&](int a) { // G 
        return a >= x && a < x + y;
    };
    auto inZ = [&](int a) { // B
        return a >= x + y && a < x + y + z;
    };
    while (!q.empty()) {
        auto [u, v] = q.front();
        q.pop();

        if (rel[u][v] == -1) {
            std::swap(u, v);
        }

        if (inX(u) && inY(v)) {
            int nu = u, nv = v - x;
            for (int i = x + y; i < x + y + z; i++) {
                int ni = i - x - y;
                char c = s[nu][nv][ni];
                if (c == 'R') {
                    add(i, v);
                    add(i, u);
                } else if (c == 'G') {
                    add(u, i);
                    add(v, i);
                } else {
                    add(u, i);
                    add(i, v);
                }
            }
        } else if (inX(u) && inZ(v)) {
            int nu = u, nv = v - x - y;
            for (int i = x; i < x + y; i++) {
                int ni = i - x;
                char c = s[nu][ni][nv];
                if (c == 'R') {
                    add(i, u);
                    add(i, v);
                } else if (c == 'G') {
                    add(u, i);
                    add(i, v);
                } else {
                    add(v, i);
                    add(u, i);
                }
            }
        } else if (inY(u) && inX(v)) {
            int nu = u - x, nv = v;
            for (int i = x + y; i < x + y + z; i++) {
                int ni = i - x - y;
                char c = s[nv][nu][ni];
                if (c == 'R') {
                    add(u, i);
                    add(v, i);
                } else if (c == 'G') {
                    add(i, u);
                    add(i, v);
                } else {
                    add(u, i);
                    add(i, v);
                }
            }
        } else if (inY(u) && inZ(v)) {
            int nu = u - x, nv = v - x - y;
            for (int i = 0; i < x; i++) {
                int ni = i;
                char c = s[ni][nu][nv];
                if (c == 'R') {
                    add(u, i);
                    add(i, v);
                } else if (c == 'G') {
                    add(i, u);
                    add(i, v);
                } else {
                    add(v, i);
                    add(u, i);
                }
            }
        } else if (inZ(u) && inX(v)) {
            int nu = u - x - y, nv = v;
            for (int i = x; i < x + y; i++) {
                int ni = i - x;
                char c = s[nv][ni][nu];
                if (c == 'R') {
                    add(v, i);
                    add(u, i);
                } else if (c == 'G') {
                    add(u, i);
                    add(i, v);
                } else {
                    add(i, u);
                    add(i, v);
                }
            }
        } else if (inZ(u) && inY(v)) {
            int nu = u - x - y, nv = v - x;
            for (int i = 0; i < x; i++) {
                int ni = i;
                char c = s[ni][nv][nu];
                if (c == 'R') {
                    add(u, i);
                    add(i, v);
                } else if (c == 'G') {
                    add(v, i);
                    add(u, i);
                } else {
                    add(i, u);
                    add(i, v);
                }
            }
        }
    }

    std::vector<std::vector<int>> adj(n);
    std::vector<int> in(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (rel[i][j] == 1) {
                adj[i].push_back(j);
                in[j]++;
            }
        }
    }

    std::queue<int> nq;
    for (int i = 0; i < n; i++) {
        if (in[i] == 0) {
            nq.push(i);
        }
    }

    int rank = 1;
    std::vector<int> ans(n);
    while (!nq.empty()) {
        auto u = nq.front();
        nq.pop();
        ans[u] = rank++;
        for (auto v : adj[u]) {
            in[v]--;
            if (in[v] == 0) {
                nq.push(v);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << ans[i];
        if (i == x - 1 || i == x + y - 1 || i == x + y + z - 1) {
            std::cout << "\n";
        } else {
            std::cout << " ";
        }
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
