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

	int n, m;
	std::cin >> n >> m;

	DSU dsu(n);
	std::vector<int> time;
	while (m--) {
		int op;
		std::cin >> op;

		if (op == 1) {
			time.push_back(dsu.time());
			int x, y;
			std::cin >> x >> y;
			x--, y--;
			dsu.merge(x, y);
		} else if (op == 2) {
			if (!time.empty()) {
				int t = time.back();
				time.pop_back();
				dsu.revert(t);
			}
		} else {
			int x, y;
			std::cin >> x >> y;
			x--, y--;
			std::cout << (dsu.same(x, y) ? "Yes" : "No") << "\n";
		}
	}


	return 0;
}