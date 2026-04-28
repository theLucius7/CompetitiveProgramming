#include <bits/stdc++.h>

using i64 = long long;

struct DSU {
    std::vector<int> f, siz;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
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
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};

struct Edge {
    int a, b, w, x;
};

void solve() {
    int n;
    std::cin >> n;

    std::vector<Edge> edges(n);
    int max = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        edges[i] = {a, b, b - a, i + 1};
        max = std::max({max, a, b});
    }

    std::sort(edges.begin(), edges.end(), [](const Edge &x, const Edge &y) {
        return x.w > y.w;
    });

    DSU dsu(max + 1);
    std::vector<int> ans;
    for (auto &[a, b, w, x] : edges) {
        if (dsu.merge(a, b)) {
            ans.push_back(x);
        }
    }

    int cnt = ans.size();
    std::cout << cnt << "\n";

    for (int i = 0; i < cnt; i++) {
        std::cout << ans[i] << " \n"[i + 1 == cnt];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
