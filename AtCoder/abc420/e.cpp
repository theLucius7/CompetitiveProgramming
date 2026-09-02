#include <bits/stdc++.h>

using i64 = long long;

struct DSU {
    std::vector<int> f, siz, v;
    
    DSU() {}
    
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
        v.assign(n, 0);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        
        if (siz[x] < siz[y]) std::swap(x, y);
        siz[x] += siz[y];
        f[y] = x;
        
        v[x] = v[x] || v[y];
        
        return true;
    }
    
    void set(int x, int c) {
        int root = find(x);
        v[root] = c;
    }
    
    bool cnt(int x) {
        return v[find(x)] == 1;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, Q;
    std::cin >> N >> Q;

    DSU dsu(N + 1);

    while (Q--) {
        int op;
        std::cin >> op;

        if (op == 1) {
            int u, v;
            std::cin >> u >> v;
            dsu.merge(u, v);
        } else if (op == 2) {
            int v;
            std::cin >> v;
            dsu.set(v, !dsu.cnt(v));
        } else if (op == 3) {
            int v;
            std::cin >> v;
            if (dsu.cnt(v)) {
                std::cout << "Yes\n";
            } else {
                std::cout << "No\n";
            }
        }
    }

    return 0;
}
