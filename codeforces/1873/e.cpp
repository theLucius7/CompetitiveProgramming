#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    i64 n, x;
    std::cin >> n >> x;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    i64 lo = 1, hi = 2E9 + 10;
    while (lo < hi) {
        int m = (lo + hi + 1) / 2;

        i64 sum = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] < m) {
                sum += m - a[i];
            }
        }

        if (sum <= x) {
            lo = m;
        } else {
            hi = m - 1;
        }
    }

    std::cout << lo << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }


    return 0;
}