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

	std::vector<std::vector<int>> A(M);
	std::vector<int> C(M);
	for (int i = 0; i < M; i++) {
		int K;
		std::cin >> K >> C[i];
		A[i].resize(K);
		for (int j = 0; j < K; j++) {
			std::cin >> A[i][j];
			A[i][j]--;
		}
	}

	std::vector<int> P(M);
	std::iota(P.begin(), P.end(), 0);
	std::sort(P.begin(), P.end(), [&](int i, int j) {
		return C[i] < C[j];
	});

	DSU dsu(N);
	int comp = N;
	i64 ans = 0;
	for (auto i : P) {
		for (int j = 0; j < A[i].size() - 1; j++) {
			if (dsu.merge(A[i][j], A[i][j + 1])) {
				comp--;
				ans += C[i];
			}
		}
	}

	std::cout << (comp > 1 ? -1 : ans) << "\n";


	return 0;
}