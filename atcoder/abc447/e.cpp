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

	constexpr i64 P = 998244353;

	int N, M;
	std::cin >> N >> M;

	std::vector<i64> f(M + 1);
	f[0] = 1;
	for (int i = 1; i <= M; i++) {
		f[i] = f[i - 1] * 2 % P;
	}

	std::vector<std::pair<int, int>> edges(M);
	for (int i = 0; i < M; i++) {
		int X, Y;
		std::cin >> X >> Y;
		X--, Y--;
		edges[i] = {X, Y};
	}

	DSU dsu(N);
	int cnt = N;
	i64 ans = 0;
	for (int i = M - 1; i >= 0; i--) {
		auto [x, y] = edges[i];
		if (!dsu.same(x, y)) {
			if (cnt == 2) {
				ans += f[i + 1];
				ans %= P;
			} else {
				dsu.merge(x, y);
				cnt--;
			}
		}
	}
	std::cout << ans << "\n";

	return 0;
}