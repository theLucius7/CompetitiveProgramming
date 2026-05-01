#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    
    int ans = 0, n = s.size();
    int min = n;
    for (int x = 0, y = -1; x <= n; x++) {
        if (x < n && s[x] == 'A') {
            ans++;
        } else {
            min = std::min(min, x - y - 1);
            y = x;
        }
    }
    ans -= min;
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
    
    return 0;
}