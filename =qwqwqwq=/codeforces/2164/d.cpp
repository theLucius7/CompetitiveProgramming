#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, max;
    std::cin >> n >> max;

    std::string s, t;
    std::cin >> s >> t;
    
    std::vector<int> pos[310];
    for (int i = 0; i < n; i++) {
        pos[s[i]].push_back(i);
    }
    
    std::array<int, 310> vis{};
    for (int i = 0; i < n; i++) {
        vis[s[i]] = 1;
        if (!vis[t[i]]) {
            std::cout << -1 << "\n";
            return;
        }
    }
    
    auto check = [&](int T) -> std::vector<int> {
        if (s[0] != t[0]) {
            return {};
        }
        std::vector<int> p(n);
        p[0] = 0;
        int L = 0;
        for (int i = 1; i < n; i++) {
            L = std::max(L, i - T);
            auto &v = pos[t[i]];
            auto it = std::lower_bound(v.begin(), v.end(), L);
            if (it == v.end() || *it > i) {
                return {};
            }
            p[i] = *it;
            L = p[i];
        }
        return p;
    };
    
    int lo = 0, hi = n - 1, ans = -1;
    std::vector<int> P;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        auto p = check(mid);
        if (!p.empty()) {
            ans = mid;
            P = p;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    
    if (ans < 0 || ans > max) {
        std::cout << -1 << "\n";
        return;
    }
    
    std::cout << ans << "\n";
    for (int cnt = 0; cnt < ans; cnt++) {
        std::string nxt = s;
        for (int i = n - 1; i >= 1; i--) {
            if (i - cnt - 1 >= P[i]) {
                nxt[i] = s[i - 1];
            }
        }
        std::cout << nxt << "\n";
        s = nxt;
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