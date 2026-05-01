#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) {
        std::cin >> l[i] >> r[i];
    }

    int ans = *std::ranges::partition_point(std::ranges::iota_view(0, int(1E9) + 1), 
        [&](int k) {
            int L = 0, R = 0;
            for (int i = 0; i < n; i++) {
                L -= k;
                R += k;
                L = std::max(L, l[i]);
                R = std::min(R, r[i]);
                if (L > R) {
                    return true;
                }
            }
            return false;
        });
    std::cout << ans << "\n";
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