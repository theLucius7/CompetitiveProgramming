#include <bits/stdc++.h>

using i64 = long long;

struct DSU {
    std::vector<int> f, siz;
    std::vector<int> val;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
        val.resize(n);
    }
    
    int find(int x) {
        if (x == f[x]) {
        	return x;
        }
        int root = find(f[x]);
        val[x] += val[f[x]];
        return f[x] = root;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y, int w) {
        int nx = find(x), ny = find(y);
        if (nx == ny) {
            return false;
        }
        
        if (siz[nx] < siz[ny]) {
        	std::swap(nx, ny);
        	std::swap(x, y);
        	w *= -1;
        }

	    siz[nx] += siz[ny];
	    val[ny] = val[x] + w - val[y];
	    f[ny] = nx;

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
    while (m--) {
    	int op;
    	std::cin >> op;

    	if (op == 1) {
    		int i, j, w;
    		std::cin >> i >> j >> w;
    		i--, j--;
    		dsu.merge(i, j, w);
    	} else {
    		int i, j;
    		std::cin >> i >> j;
    		i--, j--;
    		if (dsu.same(i, j)) {
    			std::cout << dsu.val[j] - dsu.val[i] << "\n";
    		} else {
    			std::cout << "unknown\n";
    		}
    	}
    }

	return 0;
}