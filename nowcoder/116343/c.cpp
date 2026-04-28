#include <bits/stdc++.h>

using i64 = long long;

using i128 = __int128;

int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    auto check = [&](i64 a, i64 m) -> bool {
        return (i128)m * (m + 1) / 2 >= a;
    };


    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        i64 a;
        std::cin >> a;

        i64 lo = 1, hi = 2E9;
        while (lo < hi) {
            i64 m = (lo + hi) / 2;
            if (check(a, m)) {
                hi = m;
            } else {
                lo = m + 1;
            }
        }
        ans += lo;
    }
    std::cout << ans << "\n";


    return 0;
}