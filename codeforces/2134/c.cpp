#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    i64 inf = LLONG_MAX;
    i64 ans = 0, b = 0, c = inf, d = inf;
    for (int i = 0; i < n; i++) {
        i64 v = ((i + 1) & 1) ? a[i] : -a[i];
        i64 nb = b + v;
        i64 M = std::min(c, d);
        if (M != inf && nb > M) {
            ans += nb - M;
            nb = M;
        }
        d = std::min(d, c);
        c = b;
        b = nb;
    }

    std::cout << ans << "\n";
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
