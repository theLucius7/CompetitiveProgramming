#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
struct Fenwick {
    int n, m;
    std::vector<std::vector<T>> a;
    
    Fenwick(int n_ = 0, int m_ = 0) {
        init(n_, m_);
    }
    
    void init(int n_, int m_) {
        n = n_, m = m_;
        a.assign(n, std::vector<T>(m_, T{}));
    }
    
    void add(std::pair<int, int> x, const T &v) {
        for (int i = x.first + 1; i <= n; i += i & -i) {
            for (int j = x.second + 1; j <= m; j += j & -j) {
            	a[i - 1][j - 1] = a[i - 1][j - 1] + v;
            }
        }
    }
    
    T sum(std::pair<int, int> x) {
        T ans{};
        for (int i = x.first; i > 0; i -= i & -i) {
        	for (int j = x.second; j > 0; j -= j & -j) {
        		ans = ans + a[i - 1][j - 1];
        	}
        }
        return ans;
    }
    
    T rangeSum(std::pair<int, int> x, std::pair<int, int> y) {
        return sum({y.first + 1, y.second + 1}) - sum({y.first + 1, x.second}) - sum({x.first, y.second + 1}) + sum({x.first, x.second});
    }
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	std::cin >> n >> m;

	Fenwick<i64> fen(n + 1, m + 1);

	int op;
	while (std::cin >> op) {
		if (op == 1) {
			int a, b, c, d, k;
			std::cin >> a >> b >> c >> d >> k;
			a--, b--, c--, d--;
			fen.add({c + 1, d + 1}, k);
			fen.add({c + 1, b}, -k);
			fen.add({a, d + 1}, -k);
			fen.add({a, b}, k);
		} else {
			int x, y;
			std::cin >> x >> y;
			x--, y--;
			std::cout << fen.sum({x + 1, y + 1}) << "\n";
		}
	}

	return 0;
}