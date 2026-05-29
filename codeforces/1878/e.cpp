#include <bits/stdc++.h>

using i64 = long long;

template<class T, class Cmp = std::less<T>>
struct RMQ {
    const int n;
    const Cmp cmp;
    std::vector<std::vector<T>> a;
    RMQ(const std::vector<T> &init) : n(init.size()), cmp(Cmp()) {
        int lg = std::__lg(n);
        a.assign(n, std::vector<T>(lg + 1));
        for (int j = 0; j <= lg; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                a[i][j] = (j == 0 ? init[i] : a[i][j - 1] & a[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    T rangeAnd(int l, int r) {
        int k = std::__lg(r - l);
        return a[l][k] & a[r - (1 << k)][k];
    }
};

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    auto cmpAnd = [](int x, int y) {
        return x & y;
    };

    RMQ<int, decltype(cmpAnd)> st(a);

    int q;
    std::cin >> q;

    for (int i = 0; i < q; i++) {
        int l, k;
        std::cin >> l >> k;
        l--;

        if (k > a[l]) {
            std::cout << -1 << " \n"[i == q - 1];
            continue;
        }

        int lo = l, hi = n - 1;
        while (lo < hi) {
            int m = (lo + hi + 1) / 2;
            if (st.rangeAnd(l, m + 1) >= k) {
                lo = m;
            } else {
                hi = m - 1;
            }
        }

        std::cout << lo + 1 << " \n"[i == q - 1];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }


    return 0;
}