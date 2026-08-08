#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);

    std::map<int, int> cnt;
    int mx = 0, mxcnt = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        cnt[a[i]]++;
        if (cnt[a[i]] > mxcnt) {
            mxcnt = cnt[a[i]];
            mx = a[i];
        }
    }

    std::cout << std::accumulate(a.begin(), a.end(), 0LL) - std::max(0LL, mxcnt - (n - mxcnt) - 2) * mx << "\n";


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
