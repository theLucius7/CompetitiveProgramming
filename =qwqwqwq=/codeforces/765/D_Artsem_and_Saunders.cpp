#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> f(n);
    std::set<int> s;
    for (int i = 0; i < n; i++) {
        std::cin >> f[i];
        f[i]--;
        s.insert(f[i]);
    }

    for (int i = 0; i < n; i++) {
        if (f[f[i]] != f[i]) {
            std::cout << -1 << "\n";
            return;
        }
    }

    std::vector<int> h;
    for (auto x : s) {
        h.push_back(x);
    }

    std::vector<int> g(n);
    for (int i = 0; i < n; i++) {
        g[i] = std::distance(h.begin(), std::lower_bound(h.begin(), h.end(), f[i]));
    }
    std::cout << h.size() << "\n";
    for (int i = 0; i < n; i++) {
        std::cout << g[i] + 1 << " \n"[i == n - 1];
    }
    for (int i = 0; i < h.size(); i++) {
        std::cout << h[i] + 1 << " \n"[i == h.size() - 1];
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
