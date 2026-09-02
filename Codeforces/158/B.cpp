#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> s(n);
    std::vector<int> cnt(5);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
        cnt[s[i]]++;
    }
    int ans = cnt[4];

    int mn31 = std::min(cnt[3], cnt[1]);
    ans += cnt[3];
    cnt[3] = 0;
    cnt[1] -= mn31;

    ans += cnt[2] / 2;
    cnt[2] %= 2;

    if (cnt[2]) {
        ans++;
        cnt[2] = 0;
        cnt[1] = std::max(0LL, cnt[1] - 2);
    } 

    ans += (cnt[1] + 3) / 4;
    std::cout << ans << "\n";
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
