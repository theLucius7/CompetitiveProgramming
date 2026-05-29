std::vector<bool> vis(N);
vis[0] = true;

auto f = A[0];

std::vector<std::vector<std::pair<int, int>>> adj(N);

for (int _ = 1; _ < N; _++) {
    int x = -1;
    for (int i = 0; i < N; i++) {
        if (!vis[i] && (x == -1 || f[i] < f[x])) {
            x = i;
        }
    }
    for (int i = 0; i < N; i++) {
        if (vis[i] && f[x] == A[x][i]) {
            adj[x].emplace_back(i, f[x]);
            adj[i].emplace_back(x, f[x]);
            break;
        }
    }
    vis[x] = true;
    for (int i = 0; i < N; i++) {
        f[i] = std::min(f[i], A[x][i]);
    }
}