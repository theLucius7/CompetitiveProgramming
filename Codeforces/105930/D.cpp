#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
    int n, q;
    std::cin >> n >> q;

    std::vector<i64> d(n + 5);
    while (q--) {
        i64 l, D;
        std::cin >> l >> D;

        
        i64 a = 0 + D;
        i64 b = l - 1 + D;

        i64 k = a / n;
        i64 r = a % n;
        d[0] -= k, d[n] += k;
        d[0] -= 1, d[r] += 1;

        k = b / n;
        r = b % n;
        d[0] += k, d[n] -= k;
        d[0] += 1, d[r + 1] -= 1;
    }

    for (int i = 0; i < n; i++) {
        if (i) {
            d[i] += d[i - 1];
        }
        std::cout << d[i] << " \n"[i == n - 1];
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }


    return 0;
}