auto bfs = [&](int s) {
        std::queue<int> q;
        std::vector d(n, -1);
        d[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (auto y : adj[x]) {
                if (d[y] == -1) {
                    d[y] = d[x] + 1;
                    q.push(y);
                }
            }
        }
        return d;
    };

    auto d0 = bfs(0);
    int s = std::max_element(d0.begin(), d0.end()) - d0.begin();

    auto ds = bfs(s);
    int t = std::max_element(ds.begin(), ds.end()) - ds.begin();
