#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;
    
    Fenwick(int n_ = 0) {
        init(n_);
    }
    
    void init(int n_) {
        n = n_;
        a.assign(n, T{});
    }
    
    void add(int x, const T &v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] = a[i - 1] + v;
        }
    }
    
    T sum(int x) {
        T ans{};
        for (int i = x; i > 0; i -= i & -i) {
            ans = ans + a[i - 1];
        }
        return ans;
    }
    
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
    
    int select(const T &k) {
        int x = 0;
        T cur{};
        for (int i = 1 << std::__lg(n); i; i /= 2) {
            if (x + i <= n && cur + a[x + i - 1] <= k) {
                x += i;
                cur = cur + a[x - 1];
            }
        }
        return x;
    }
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, M;
    std::cin >> N >> M;

    std::vector<int> a(N);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }

    Fenwick<int> fen(N);
    for (int i = 0; i < N; i++) {
        if (i == 0) {
            fen.add(i, a[i]);
        } else {
            fen.add(i, a[i] - a[i - 1]);
        }
    }

    while (M--) {
        int op;
        std::cin >> op;

        if (op == 1) {
            int x, y, k;
            std::cin >> x >> y >> k;
            x--, y--;
            fen.add(x, k);
            fen.add(y + 1, -k);
        } else {
            int x;
            std::cin >> x;
            x--;
            std::cout << fen.sum(x + 1) << "\n";
        }
    }

	return 0;
}