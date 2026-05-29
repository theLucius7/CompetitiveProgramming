#include <bits/stdc++.h>

using i64 = long long;

#define int long long

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


void solve() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N), B(N);
    std::set<int> set;
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        set.insert(A[i]);
    }
    for (int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    std::vector<std::deque<int>> pos(N + 1);
    for (int i = 0; i < N; i++) {
        pos[B[i]].push_back(i);
    }

    std::vector<int> C(N);
    for (int i = 0; i < N; i++) {
        C[i] = pos[A[i]].front();
        pos[A[i]].pop_front();
    }

    Fenwick<int> fen(N + 5);
    i64 cnt = 0;
    for (int i = 0; i < N; i++) {
        cnt += fen.rangeSum(C[i] + 1, N + 2);
        fen.add(C[i], 1);
    }

    i64 x = (cnt + K - 1) / K;
    if (set.size() != N || (x % 2) * (K % 2) % 2 == cnt % 2) {
        std::cout << x << "\n";
    } else if (K % 2 == 1) {
        std::cout << x + 1 << "\n";
    } else {
        std::cout << -1 << "\n";
    }

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
