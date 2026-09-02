#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<std::pair<std::string, int>> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i].first >> a[i].second;
    }


    for (int x = 0; x <= 9999; x++) {
        std::string t = std::to_string(x);
        while (t.size() < 4) {
            t = "0" + t;
        }
        bool ok = true;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < 4; j++) {
                if (a[i].first[j] == t[j]) {
                    cnt++;
                }
            }
            if (cnt != a[i].second) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            continue;
        } else {
            std::cout << t << "\n";
            return;
        }
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
