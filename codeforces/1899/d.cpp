#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::map<int, i64> cnt;
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;

        ans += cnt[a]++;
    }

    ans += cnt[1] * cnt[2];
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