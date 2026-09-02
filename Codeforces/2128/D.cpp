#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<i64> nxt(n, n);
    std::stack<i64> stk;
    for (int i = 0; i < n; i++) {
        while (!stk.empty() && a[stk.top()] < a[i]) {
            nxt[stk.top()] = i;
            stk.pop();
        }
        stk.push(i);
    }

    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        ans += 1LL * (nxt[i] - i) * (i + 1);
    }

    std::cout << ans << "\n";
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
