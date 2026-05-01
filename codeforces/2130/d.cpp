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

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> p(n), v;
    v.reserve(2 * n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
        v.push_back(p[i]);
        v.push_back(2 * n - p[i]);
    }

    std::sort(v.begin(), v.end());

    std::vector<std::pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = {std::lower_bound(v.begin(), v.end(), p[i]) - v.begin(), std::lower_bound(v.begin(), v.end(), 2 * n - p[i]) - v.begin()};
    }

    i64 ans = 0x3f3f3f;
    std::vector<int> V(n);
    auto dfs = [&](auto self, int i) -> void {
        if (i == n) {
            Fenwick<int> fen(v.size());
            i64 cnt = 0;
            for (int j = n - 1; j >= 0; j--) {
                cnt += fen.sum(V[j]);
                fen.add(V[j], 1);
            }
            ans = std::min(ans, cnt);
            return;
        }

        V[i] = a[i].first;
        self(self, i + 1);
        V[i] = a[i].second;
        self(self, i + 1);
    };

    dfs(dfs, 0);
    std::cout << ans << "\n";
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
