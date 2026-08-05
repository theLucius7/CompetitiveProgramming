#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;

    std::multiset<int> a;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        a.insert(x);
    }

    int sum = 0;
    std::vector<int> b;
    while (b.size() < n) {
        auto it = a.upper_bound(-sum);
        if (it == a.end()) {
            std::cout << "-1\n";
            // for (auto x : b) {
            //     std::cout << x << " ";
            // }
            // std::cout << "\n";
            return;
        }

        sum += *it;
        a.erase(it);

        b.push_back(sum);
    }

    for (auto x : b) {
        std::cout << x << " ";
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
