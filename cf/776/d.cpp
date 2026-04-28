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

	int n, m;
	std::cin >> n >> m;

	std::vector<int> r(n);
	for (int i = 0; i < n; i++) {
		std::cin >> r[i];
	}

	std::vector<std::vector<int>> who(n);
	for (int i = 0; i < m; i++) {
		int x;
		std::cin >> x;
		for (int j = 0; j < x; j++) {
			int a;
			std::cin >> a;
			a--;
			who[a].push_back(i);
		}
	}

	auto T = [&](int x) {
		return x;
	};
	auto F = [&](int x) {
		return x + m;
	};

	DSU dsu(2 * m);
	for (int i = 0; i < n; i++) {
		int x = who[i][0], y = who[i][1];
		if (r[i] == 0) {
			dsu.merge(T(x), F(y));
			dsu.merge(F(x), T(y));
		} else {
			dsu.merge(T(x), T(y));
			dsu.merge(F(x), F(y));
		}
	}

	for (int i = 0; i < m; i++) {
		if (dsu.same(T(i), F(i))) {
			std::cout << "NO\n";
			return 0;
		}
	}
	std::cout << "YES\n";


	return 0;
}