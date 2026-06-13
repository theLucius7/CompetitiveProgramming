#include <bits/stdc++.h>

#define int long long

constexpr int inf = 1E18;

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector maxl(n + 1, std::vector<int>((n + 1) / 2 + 2, -1));
    std::vector minr(n + 1, std::vector<int>((n + 1) / 2 + 2, inf));
    for (int l = 0; l < n; l++) {
        std::set<int> set;
        for (int r = l; r < std::min(n, l + n / 2); r++) {
            set.insert(a[r]);
            if (*set.rbegin() - *set.begin() == set.size() - 1 && set.size() == r - l + 1) {
                maxl[*set.begin()][r - l + 1] = std::max(maxl[*set.begin()][r - l + 1], l);
                minr[*set.begin()][r - l + 1] = std::min(minr[*set.begin()][r - l + 1], r);
            }
        }
    }

    // std::cout << minr[1][1] << " " << maxl[2][1] << "?\n";

    for (int len = n / 2; len >= 1; len--) {
        for (int l = 1; l + 2 * len - 1 <= n; l++) {
            if (minr[l][len] < maxl[l + len][len] || minr[l + len][len] < maxl[l][len]) {
                std::cout << len << "\n";
                return;
            }
        }
    }
    std::cout << 0 << "\n";
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
