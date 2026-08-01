#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::vector<int> id(n + 1, n - 1);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'x') {
            cnt++;
            id[cnt] = i;
        }
    }

    int co = 0, cx = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'o') {
            co++;
        } else {
            cx++;
        }

        std::cout << id[cx + co] + 1 << "\n";
    }
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
