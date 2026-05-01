#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int cur = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (cur + a[i].size() <= m) {
            cur += a[i].size();
            cnt++;
        } else {
            break;
        }
    }
    std::cout << cnt << "\n";
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