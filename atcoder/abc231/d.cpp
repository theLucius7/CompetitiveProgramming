#include <bits/stdc++.h>

using i64 = long long;

using real = long double;

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

	DSU dsu(N);
	std::vector<int> d(N);
	for (int i = 0; i < M; i++) {
		int A, B;
		std::cin >> A >> B;
		A--, B--;
		d[A]++, d[B]++;
		if (d[A] > 2 || d[B] > 2 || dsu.same(A, B)) {
			std::cout << "No\n";
			return 0;
		}
		dsu.merge(A, B);
	}

	std::cout << "Yes" << "\n";

	

	return 0;
}