#include <bits/stdc++.h>

#define int long long

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

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> A(N + 1);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    Fenwick<i64> f1(5E5 + 10), f2(5E5 + 10);
    for (int i = 0; i < N; i++) {
        f1.add(A[i], A[i]);
        f2.add(A[i], 1);
    }

    while (Q--) {
        int op;
        std::cin >> op;

        if (op == 1) {
            int x, y;
            std::cin >> x >> y;
            x--;
            f1.add(A[x], -A[x]);
            f1.add(y, y);
            f2.add(A[x], -1);
            f2.add(y, 1);
            A[x] = y;
        } else {
            int l, r;
            std::cin >> l >> r;
            if (l <= r) {
                std::cout << f1.rangeSum(l, r + 1) + f2.sum(l) * l + f2.rangeSum(r + 1, 5E5 + 1) * r << "\n";
            } else {
                std::cout << l * N << "\n";
            }
        }
    }

    return 0;
}
