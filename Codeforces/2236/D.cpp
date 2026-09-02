#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

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
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());
    std::set<int> s;
    std::map<int, int> cnt;
    for (int l = 0, r = 0; l < n; l = r) {
        while (r < n && a[l] == a[r]) {
            r++;
        }
        s.insert(a[l]);
        cnt[a[l]] = r - l;
        // std::cout << a[l] << " " << cnt[a[l]] << "\n";
    }
    // std::cout << "\n";

    Fenwick<int> t(n + 10);

    for (auto it = s.rbegin(); it != s.rend(); it++) {
        int sum = t.rangeSum(*it, std::min(n + 1, *it + k + 1));
        if (sum) {
            std::cout << "YES\n";
            return;
        }

        if (cnt[*it] % 2 == 0) {
            std::cout << "YES\n";
            return;
        } else {
            t.add(*it, 1);
        }
    }
    std::cout << "NO\n";

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
