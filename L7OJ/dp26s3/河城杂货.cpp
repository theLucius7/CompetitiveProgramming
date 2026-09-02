#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n), b(n + 1);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n + 1; i++) {
        std::cin >> b[i];
    }
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    std::vector<i128> pre(n + 1), suf(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i] * b[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = suf[i + 1] + a[i] * b[i + 1];
    }

    auto check = [&](int mid) {
        int p = std::lower_bound(a.begin(), a.end(), mid) - a.begin();
        return pre[p] + (i128)mid * b[p] + suf[p] >= (i128)m;
    };

    int lo = 0, hi = 1E9 + 10;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    std::cout << lo << "\n";
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
