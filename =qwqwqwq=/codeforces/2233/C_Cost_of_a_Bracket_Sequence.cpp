#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    std::vector<int> pre(n + 1), suf(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + (s[i] == '(');
    }
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = suf[i + 1] + (s[i] == ')');
    }

    constexpr int inf = 1E18;
    int mn = inf, p = -1;
    for (int i = 0; i <= n; i++) {
        if (pre[i] + suf[i] < mn) {
            mn = pre[i] + suf[i];
            p = i;
        }
    }

    std::vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        if (i < p && s[i] == '(' && k) {
            k--;
            ans[i] = 1;
        } else if (i >= p && s[i] == ')' && k) {
            k--;
            ans[i] = 1;
        }
    }

    // for (int i = 0; i < n; i++) {
    //     if (!ans[i] && k) {
    //         k--;
    //         ans[i] = 1;
    //     }
    // }
    for (int i = 0; i < n; i++) {
        std::cout << ans[i];
    }
    std::cout << "\n";
    
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
