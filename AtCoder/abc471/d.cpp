#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int Q, V;
    std::cin >> Q >> V;

    constexpr int inf = 1E18;
    int base = inf;
    std::priority_queue<int> q;
    while (Q--) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int t, w;
            std::cin >> t >> w;
            q.push(base - t + w);
        } else {
            int t;
            std::cin >> t;
            if (!q.empty()) {
                auto x = q.top();
                q.pop();
                std::cout << std::min(V, x - base + t) << "\n";
            } else {
                std::cout << "-1\n";
            }
        }
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
