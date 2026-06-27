#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::vector<std::pair<int, int>> stk;
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;

        if (stk.empty() || stk.back().first != a) {
            stk.push_back({a, 1});
        } else if (stk.back().first == a) {
            stk.back().second++;
            if (stk.back().second == k) {
                stk.pop_back();
            }
        }
    }

    std::cout << std::accumulate(stk.begin(), stk.end(), 0,
        [](int sum, auto &p) {
            return sum + p.second;
        }
    ) << "\n";

    for (auto [x, cnt] : stk) {
        for (int i = 0; i < cnt; i++) {
            std::cout << x << " ";
        }
    }
    std::cout << "\n";
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
