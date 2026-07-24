#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, m, k;
    std::cin >> m >> n >> k;

    std::priority_queue<std::tuple<int, int, int, int>, std::vector<std::tuple<int, int, int, int>>, std::greater<>> sbms;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        a--;
        sbms.push({b, i, c, a});
    }

    std::priority_queue<int, std::vector<int>, std::greater<>> status;
    for (int i = 0; i < k; i++) {
        status.push(0);
    }

    std::vector<int> judged(m), ans(n);
    while (sbms.size()) {
        auto [t, sbmsi, len, tmi] = sbms.top();
        sbms.pop();

        if (t < judged[tmi]) {
            t = judged[tmi];
            sbms.push({t, sbmsi, len, tmi});
            continue;
        }

        auto ojt = status.top();
        status.pop();

        ans[sbmsi] = std::max(ojt, t);
        int nt = std::max(ojt, t) + len;
        judged[tmi] = nt;
        status.push(nt);
    }

    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << " \n"[i == n - 1];
    }
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
