#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

using i64 = long long;

i64 mul(i64 a, i64 b, i64 p) {
    i64 c = a * b - i64(1.0L * a * b / p) * p;
    c %= p;
    if (c < 0) {
        c += p;
    }
    return c;
}

i64 power(i64 a, i64 b, i64 p) {
    i64 res = 1;
    for (; b; b /= 2, a = mul(a, a, p)) {
        if (b % 2) {
            res = mul(res, a, p);
        }
    }
    return res;
}

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    std::map<int, bool> has;
    int cnt = 0;
    int cnt1f = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        if (a[i] > -1) {
            if (!has.contains(a[i])) {
                cnt += has.contains(a[i] - 1) + has.contains(a[i] + 1);
                has[a[i]] = true;
            }
        } else {
            cnt1f++;
        }              
    }

    constexpr int P = 1E9 + 7;
    int res = power(2, n - cnt1f - has.size(), P);
    if (cnt1f) {
        std::cout << (power(2, cnt1f - 1, P) * res % P) * (cnt + 1) % P << "\n";
    } else {
        std::cout << res << "\n";
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