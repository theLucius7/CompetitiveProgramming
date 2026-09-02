#include <bits/stdc++.h>

using i64 = long long;

struct DSU {
    std::vector<int> siz;
    std::vector<int> f;
    std::vector<std::array<int, 2>> his;
    
    DSU(int n) : siz(n + 1, 1), f(n + 1) {
        std::iota(f.begin(), f.end(), 0);
    }
    
    int find(int x) {
        while (f[x] != x) {
            x = f[x];
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
        if (siz[x] < siz[y]) {
            std::swap(x, y);
        }
        his.push_back({x, y});
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int time() {
        return his.size();
    }
    
    void revert(int tm) {
        while (his.size() > tm) {
            auto [x, y] = his.back();
            his.pop_back();
            f[y] = y;
            siz[x] -= siz[y];
        }
    }
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	for (int t = 0; ; t++) {
        int N, M;
        std::cin >> N >> M;

        if (N == 0 && M == 0) {
            return 0;
        }

        DSU dsu(2 * N + M);

        for (int i = 0; i < N; i++) {
            dsu.f[i] = N + i;
        }

        int cur = 2 * N + 1;
        while (M--) {
            char c;
            std::cin >> c;

            if (c == 'M') {
                int x, y;
                std::cin >> x >> y;
                dsu.merge(x, y);
            } else {
                int x;
                std::cin >> x;
                dsu.f[x] = cur++;
            }
        }

        int ans = 0;
        std::unordered_map<int, bool> vis;
        for (int i = 0; i < N; i++) {
            if (!vis[dsu.find(i)]) {
                vis[dsu.find(i)] = true;
                ans++;
            }
        }
        // std::cin >> std::ws;
        std::cout << "Case #" << t + 1 << ": " << ans << "\n";
    }

	return 0;
}