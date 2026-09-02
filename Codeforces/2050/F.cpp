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
                a[i][j] = (j == 0 ? init[i] : std::__gcd(a[i][j - 1], a[i + (1 << (j - 1))][j - 1]));
            }
        }
    }
    T rangeGcd(int l, int r) {
        int k = std::__lg(r - l);
        return std::__gcd(a[l][k], a[r - (1 << k)][k]);
    }
};

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> b(n);
    for (int i = 0; i < n - 1; i++) {
        b[i] = std::abs(a[i + 1] - a[i]);
    }

    RMQ<int> st(b);
    for (int i = 0; i < m; i++) {
        int l, r;
        std::cin >> l >> r;
        l--, r--;
        if (l == r) {
            std::cout << 0 << " \n"[i == m - 1];
            continue;
        }
        std::cout << st.rangeGcd(l, r) << " \n"[i == m - 1];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }


    return 0;
}