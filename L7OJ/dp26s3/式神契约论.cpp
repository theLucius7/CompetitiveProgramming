#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> cnt(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = i + i; j <= n; j += i) {
            cnt[i]++;
            cnt[j]++;
        }
    }

    std::vector<std::pair<int, int>> res(n);
    for (int x = 1; x <= n; x++) {
        res[x - 1] = {cnt[x], x};
    }

    std::sort(res.begin(), res.end(), std::greater<>());

    std::cout << res[k - 1].first << "\n";

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
