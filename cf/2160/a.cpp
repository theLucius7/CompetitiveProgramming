#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    int n;
    std::cin >> n;

    std::vector<bool> vis(102);
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        vis[a] = true;
    }

    for (int i = 0; i <= 101; i++) {
        if (vis[i] == false) {
            std::cout << i << "\n";
            return;
        }
    }
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
