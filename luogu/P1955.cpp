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

void solve() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> e, ne;
    std::vector<int> v;
    for (int i = 0; i < n; i++) {
        int x, y, w;
        std::cin >> x >> y >> w;
        v.push_back(x);
        v.push_back(y);
        if (w == 1) {
            e.emplace_back(x, y);
        } else {
            ne.emplace_back(x, y);
        }
    }

    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());

    for (auto &[x, y] : e) {
        x = std::lower_bound(v.begin(), v.end(), x) - v.begin();
        y = std::lower_bound(v.begin(), v.end(), y) - v.begin();
    }
    for (auto &[x, y] : ne) {
        x = std::lower_bound(v.begin(), v.end(), x) - v.begin();
        y = std::lower_bound(v.begin(), v.end(), y) - v.begin();
    }

    DSU dsu(v.size());
    for (auto [x, y] : e) {
        dsu.merge(x, y);
    }

    for (auto [x, y] : ne) {
        if (dsu.same(x, y)) {
            std::cout << "NO\n";
            return;
        }
    }
    std::cout << "YES\n";
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