struct DSU {
    std::vector<int> f, g;
    std::vector<std::array<int, 2>> siz;

    int ans = 0;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        g.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, {1, 0});
    }
    
    int find(int x) {
        if (f[x] == f[f[x]]) {
            return f[x];
        }

        find(f[x]);

        g[x] ^= g[f[x]];
        f[x] = f[f[x]];

        return f[x];
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        find(x);
        find(y);
        int w = 1 ^ g[x] ^ g[y];
        x = f[x];
        y = f[y];

        if (x == y) {
            return w == 0;
        }
        ans -= std::min(siz[x][0], siz[x][1]);
        ans -= std::min(siz[y][0], siz[y][1]);
        siz[x][0] += siz[y][w];
        siz[x][1] += siz[y][w ^ 1];
        ans += std::min(siz[x][0], siz[x][1]);
        f[y] = x;
        g[y] = w;
        return true;
    }
};