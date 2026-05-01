#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int min = INT_MAX;
    std::pair<int, int> ans;
    for (int l = 0; l <= n; l++) {
        std::vector<int> cnt(2, 0);
        for (int r = l; r < n; r++) {
            if (a[r] > a[l]) {
                cnt[0]++;
            } else if (a[l] > a[r]) {
                cnt[1]++;
            }
            if (cnt[0] - cnt[1] < min) {
                min = cnt[0] - cnt[1];
                ans = {l + 1, r + 1};
            }
        }
    }

    std::cout << ans.first << " " << ans.second << "\n";
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
