#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, k, x;
    std::cin >> n >> k >> x;

    int pre = 0, sum = 0;
    auto check = [&](int i, int m) {
        int npre = pre + m, nsum = sum + std::abs(npre);

        int S = std::abs(npre);
        int len = (S + k - 1) / k;
        return n - i - 1 >= len && S + (S % k + S - k) * len / 2 <= x;
    };

    std::vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        int lo = -k, hi = 0;
        while (lo < hi) {
            int m = (lo + hi) >> 1;
            if (check(i, m)) {
                hi = m;
            } else {
                lo = m + 1;
            }
        }

        if (check(i, lo)) {
            ans[i] = lo;
            pre += lo;
            sum += std::abs(pre);
            continue;
        }

        lo = 0, hi = k;
        while (lo < hi) {
            int m = (lo + hi + 1) / 2;
            if (check(i, m)) {
                lo = m;
            } else {
                hi = m - 1;
            }
        }

        ans[i] = lo;
        pre += lo;
        sum += std::abs(pre);
    }

    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << " \n"[i == n - 1];
    }
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
