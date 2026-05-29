#include <bits/stdc++.h>

using i64 = long long;

i64 count(i64 x) {
    if (x < 10) {
        return 0;
    }

    std::vector<int> a = {2,3,5,7};
    i64 res = x;

    for (int mask = 1; mask < (1 << 4); ++mask) {
        i64 mul = 1;
        for (int i = 0; i < 4; ++i) {
            if (mask & (1 << i)) {
                mul *= a[i];
            }
        }

        i64 cnt = x / mul;
        if (__builtin_popcount(mask) % 2 == 1){
            res -= cnt;
        } else {
            res += cnt;
        }
    }
    return res - 1;
}

void solve() {
    i64 l, r;
    std::cin >> l >> r;
    std::cout << count(r) - count(l - 1) << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
}
