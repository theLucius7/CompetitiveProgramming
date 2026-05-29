#include <bits/stdc++.h>

using i64 = long long;

struct DSU {
    std::vector<int> f, siz, cnt;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        cnt.resize(n);
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
        	cnt[x]++;
            return false;
        }
        siz[x] += siz[y];
        cnt[x] += cnt[y] + 1;
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
	
	int n, m;
	std::cin >> n >> m;

	DSU dsu(n);
	for (int i = 0; i < m; i++) {
		int x, y;
		std::cin >> x >> y;
		x--, y--;
		dsu.merge(x, y);
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (dsu.f[i] == i) {
			ans += (dsu.cnt[i] % 2 == dsu.siz[i] % 2 ? dsu.siz[i] : dsu.siz[i] - 1);
		}
	}
	std::cout << ans << "\n";


	return 0;
}