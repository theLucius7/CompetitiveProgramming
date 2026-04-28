#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> r(n);
    for (int i = 0; i < n; i++) {
        std::cin >> r[i];
    }

    std::vector<int> d(m), s(m), t(m);
    for (int i = 0; i < m; i++) {
        std::cin >> d[i] >> s[i] >> t[i];
        s[i]--;
        t[i]--;
    }

    auto check = [&](int mid) -> bool {
        std::vector<int> diff(n);
        for (int i = 0; i < mid; i++) {
            diff[s[i]] += d[i];
            if (t[i] + 1 < n) {
                diff[t[i] + 1] -= d[i];
            }
        }

        int cur = 0;
        for (int i = 0; i < n; i++) {
            cur += diff[i];
            if (cur > r[i]) {
                return false;
            }
        }
        return true;
    };

    int lo = 0, hi = m;
    while (lo < hi) {
        int m = (lo + hi + 1) / 2;
        if (check(m)) {
            lo = m;
        } else {
            hi = m - 1;
        }
    }
    if (lo < m) {
        std::cout << -1 << "\n";
        std::cout << lo + 1 << "\n";
    } else {
        std::cout << 0 << "\n";
    }

    return 0;
}
