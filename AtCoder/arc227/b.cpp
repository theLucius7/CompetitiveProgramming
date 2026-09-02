#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

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

void solve() {
    int N;
    std::cin >> N;

    std::vector<int> a(N);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());

    for (int l = 0, r = 0; l < N; l = r) {
        while (r < N && a[l] == a[r]) {
            r++;
        }
        if (a[l] > l) {
            std::cout << "No\n";
            return;
        }
    }
    std::cout << "Yes\n";

    std::vector<int> ans(5E5 + 10);
    DSU dsu(5E5 + 10);
    for (int i = N - 1; i >= 0; i--) {
        int x = a[i];
        auto p = dsu.find(x);
        ans[p] = x;
        dsu.merge(p + 1, p);
    }

    for (int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
    }

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
