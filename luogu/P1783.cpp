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

    std::vector<int> X(M), Y(M);
    for (int i = 0; i < M; i++) {
        std::cin >> X[i] >> Y[i];
    }

    std::vector<std::tuple<long double, int, int>> v;
    for (int i = 0; i < M; i++) {
        v.emplace_back(X[i], 0, i + 1);
        v.emplace_back(N - X[i], i + 1, N + 1);
    }
    for (int i = 0; i < M; i++) {
        for (int j = i + 1; j < M; j++) {
            v.emplace_back(std::hypotl(X[i] - X[j], Y[i] - Y[j]) * 0.5, i + 1, j + 1);
        }
    }
    
    std::sort(v.begin(), v.end());

    DSU dsu(N + 2);
    for (int i = 0; i < v.size(); i++) {
        auto [w, x, y] = v[i];
        dsu.merge(x, y);
        if (dsu.same(0, N + 1)) {
            std::cout << std::fixed << std::setprecision(2) << w << "\n";
            return 0;
        }
    }

	return 0;
}