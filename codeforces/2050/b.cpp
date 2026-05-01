#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i]; 
    }

    std::vector<i64> sum(2);
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            sum[0] += a[i];
        } else {
            sum[1] += a[i];
        }
    }

    if (sum[0] % ((n + 1) / 2) == 0 && sum[1] % (n / 2) == 0 && sum[0] / ((n + 1) / 2) == sum[1] / (n / 2)) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }


    return 0;
}