#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, q;
    std::cin >> n >> m >> q;

    int N = n * m;
    std::vector<int> a(N);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> a[i * m + j];
        }
    }

    std::vector<std::pair<int, int>> g(N);
    for (int i = 0; i < N; i++) {
        g.emplace_back(a[i], i);
    }

    std::vector<i64> f(N, LLONG_MAX);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

    for (int i = 0; i < m; i++) {
        f[i] = a[i];
        pq.emplace(f[i], i);
    }

    int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

    while (pq.size()) {
        auto [cur, id] = pq.top();
        pq.pop();

        int x = id / m, y = id % m;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                int nid = nx * m + ny;
                if (std::max(cur, a[nid]) < f[nid]) {
                    f[nid] = std::max(cur, a[nid]);
                    pq.emplace(f[nid], nid);
                }
            }
        }
    }

    std::sort(f.begin(), f.end());

    while (q--) {
        i64 x;
        std::cin >> x;

        std::cout << std::upper_bound(f.begin(), f.end(), x) - f.begin() << "\n";
    }

    return 0;
}
