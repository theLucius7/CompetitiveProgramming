#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

std::vector<int> C(510);

void solve() {
    int n;
    std::cin >> n;

    auto check = [&](int m) {
        return C[m] <= n;
    };

    std::vector<int> ans;
    while (n > 0) {
        int lo = 1, hi = 505;
        while (lo < hi) {
            int m = (lo + hi + 1) / 2;
            if (check(m)) {
                lo = m;
            } else {
                hi = m - 1;
            }
        }
        ans.push_back(lo);
        n -= C[lo];
    }

    std::cout << std::accumulate(ans.begin(), ans.end(), 0ll) << "\n";

    int y = 0;
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i]; j++) {
            std::cout << i << " " << y++ << "\n";
        }
    }

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    for (int i = 1; i <= 500; i++) {
        C[i] = i * (i - 1) / 2;
    }

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }
    
    return 0;
}
