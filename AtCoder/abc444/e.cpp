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

    int N;
    i64 D;
    std::cin >> N >> D;

    std::vector<i64> A(N), up(N), down(N);
    std::vector<i64> v;
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        up[i] = std::max(0LL, A[i] + D);
        down[i] = std::max(0LL, A[i] - D + 1);
        v.push_back(A[i]);
        v.push_back(up[i]);
        v.push_back(down[i]);
    }

    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());
    Fenwick<int> fen(v.size() + 10);
    for (int i = 0; i < N; i++) {
        A[i] = std::lower_bound(v.begin(), v.end(), A[i]) - v.begin();
        up[i] = std::lower_bound(v.begin(), v.end(), up[i]) - v.begin();
        down[i] = std::lower_bound(v.begin(), v.end(), down[i]) - v.begin();
    }

    int l = 0;
    i64 ans = 0;
    for (int r = 0; r < N; r++) {
        while (l <= r && fen.rangeSum(down[r], up[r]) > 0) {
            fen.add(A[l], -1);
            l++;
        }
        fen.add(A[r], 1);
        ans += r - l + 1;
    }

    std::cout << ans << "\n";



    return 0;
}