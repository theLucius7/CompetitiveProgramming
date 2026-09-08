#include <bits/stdc++.h>

using i64 = long long;

using namespace std;

const int N = 1e5 + 10, M = 110;
int n, m, q;
int w[N];
int d[N][M];
int st[N][M];
vector<int> adj[N];
vector<int> pos[M];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n >> m >> q;
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 0; j <= 100; j ++ ) {
            d[i][j] = n + 1;
        }
    }
    for (int i = 1; i <= n; i ++ ) {
        cin >> w[i];
        pos[w[i]].push_back(i);
    }
    for (int i = 1; i <= m; i ++ ) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= 100; i ++ ) {
        queue<int> q;
        for (auto j : pos[i]) {
            q.push(j);
            d[j][i] = 0;
            // cout << j << endl;
        }
        while (q.size()) {
            int u = q.front();
            q.pop();
            for (auto v : adj[u]) {
                if (!st[v][i] && d[u][i] + 1 < d[v][i]) {
                    d[v][i] = d[u][i] + 1;
                    st[v][i] = 1;
                    q.push(v);
                }
            }
        }
        for (int j = 1; j <= n; j ++ ) {
            d[j][i] = min(d[j][i], d[j][i - 1]);
        }
    }
    while (q -- ) {
        int p, a;
        cin >> p >> a;
        if (d[p][a] == n + 1) {
            d[p][a] = -1;
        }
        cout << d[p][a] << endl;
    }

    return 0;
}