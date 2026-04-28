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

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    std::vector<std::tuple<int, int, int>> v(M);
    for (int i = 0; i < M; i++) {
        int t, x, y;
        std::cin >> x >> y >> t;
        x--, y--;
        v[i] = {t, x, y};
    }

    std::sort(v.begin(), v.end());

    DSU dsu(N);
    int cnt = N;
    for (int i = 0; i < M; i++) {
        auto [t, x, y] = v[i];
        if (dsu.merge(x, y)) {
            cnt--;
        }
        if (cnt == 1) {
            std::cout << t << "\n";
            return 0;
        }
    }
    std::cout << -1 << "\n";


	return 0;
}