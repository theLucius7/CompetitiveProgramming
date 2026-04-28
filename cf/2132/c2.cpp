#include <bits/stdc++.h>

using i64 = long long;

void solve () {
    i64 n, k; 
    std::cin >> n >> k;

    auto s3 = [&](i64 u) -> i64 {
        int s = 0;
        while (u) {
            s += u % 3;
            u /= 3;
        }
        return s;
    };

    i64 s = s3(n);

    if (k < s) { 
        std::cout << -1 << "\n";
        return; 
    }

    i64 d = std::min(n, k);
    if ((d ^ n) & 1ll) {
        d--;
    }
    if (d < (i64)s) {
        std::cout << -1 << "\n";
        return;
    }

    i64 m = (n - d) / 2;
    if (m == 0) {
        std::cout << 3ll * n << "\n"; 
        return;
    }


    i64 add = 0, p = 1, q = 3;       
    while (m && n / q) {
        i64 t = std::min(n / q, m);         
        add += t * p;
        m -= t;
        p *= 3; q *= 3;
    }

    std::cout << 3ull * n + add << '\n';
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
