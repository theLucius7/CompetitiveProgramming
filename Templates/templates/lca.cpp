const int logn = std::__lg(n);
    int cur = 0;
    std::vector<int> in(n), out(n), depth(n);
    std::vector p(logn + 1, std::vector<int>(n, -1));

    auto dfs = [&](this auto &&self, int x, int fa) -> void {
        in[x] = cur++;
        p[0][x] = fa;
        for (int i = 1; i <= logn; i++) {
            p[i][x] = (p[i - 1][x] == -1 ? -1 : p[i - 1][p[i - 1][x]]);
        }
        for (auto y : adj[x]) {
            if (y == fa) {
                continue;
            }
            depth[y] = depth[x] + 1;
            self(y, x);
        }
        out[x] = cur;
    };
    dfs(0, -1);

    auto query = [&](int x, int y) {
        if (depth[x] < depth[y]) {
            std::swap(x, y);
        }

        for (int i = logn; i >= 0; i--) {
            if (depth[x] - (1 << i) >= depth[y]) {
                x = p[i][x];
            }
        }

        if (x == y) {
            return x;
        }

        for (int i = logn; i >= 0; i--) {
            if (p[i][x] != p[i][y]) {
                x = p[i][x];
                y = p[i][y];
            }
        }
        return p[0][x];
    };

    auto lift = [&](int x, int k) {
        for (int i = logn; i >= 0; i--) {
            if (k >> i & 1) {
                x = p[i][x];
            }
        }
        return x;
    };
    auto jump = [&](int x, int y, int k) {
        int lca = query(x, y);
        int dx = depth[x] - depth[lca], dy = depth[y] - depth[lca];
        if (k <= dx) {
            return lift(x, k);
        } else {
            return lift(y, dx + dy - k);
        }
    };