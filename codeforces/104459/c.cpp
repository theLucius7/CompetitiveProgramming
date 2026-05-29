#include <bits/stdc++.h>

#define int long long

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    int dx = 0, dy = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') {
            dy++;
        } else if (s[i] == 'L') {
            dy--;
        } else if (s[i] == 'D') {
            dx++;
        } else {
            dx--;
        }
    }

    int ans = 0;

    int nx = 0, ny = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') {
            ny++;
        } else if (s[i] == 'L') {
            ny--;
        } else if (s[i] == 'D') {
            nx++;
        } else {
            nx--;
        }
        ans = std::max(ans, std::abs(nx) + std::abs(ny));
    }

    nx = (k - 1) * dx, ny = (k - 1) * dy;
    ans = std::max(ans, std::abs(nx) + std::abs(ny));
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') {
            ny++;
        } else if (s[i] == 'L') {
            ny--;
        } else if (s[i] == 'D') {
            nx++;
        } else {
            nx--;
        }
        ans = std::max(ans, std::abs(nx) + std::abs(ny));
    }
    
    std::cout << ans << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }


    return 0;
}