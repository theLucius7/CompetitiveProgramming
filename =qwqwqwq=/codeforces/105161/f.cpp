#include <bits/stdc++.h>

// using namespace std;

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    long double r = 0;
    for (int i = 0; i < k - 1; i++) {
        r += a[i];
    }
    for (int i = k - 1; i < n; i++) {
        r += a[i];
        if (i - k >= 0) {
            r -= a[i - k];
        }

        long double d = r / k;
        if (d >= 1024) {
            std::cout << std::fixed << std::setprecision(7) << d / 1024 << " MiBps\n";
        } else {
            std::cout << std::fixed << std::setprecision(7) << d << " KiBps\n";
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
