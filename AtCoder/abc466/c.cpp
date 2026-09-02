#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int N;
    std::cin >> N;

    int ans = 0;
    for (int l = 0, r = 1; l < N; l++) {
        r = std::max(r, l + 1);
        while (r < N) {
            std::cout << "? " << l + 1 << " " << r + 1 << std::endl;
            std::string t;
            std::cin >> t;
            if (t == "No") {
                break;
            }
            r++;
        }
        ans += r - l - 1;
    }
    std::cout << "! " << ans << std::endl;
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
