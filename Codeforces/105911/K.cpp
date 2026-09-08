#include <bits/stdc++.h>

using i64 = long long;
using namespace std;

#define int long long

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int ans = 1E9;
    for (int x = 0; x < 4; x++) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += (a[i] - x + 4) % 4;
            
        }
        cnt += (4 - ((x + cnt) % 4 + 4) % 4) % 4;
        // std::cout << cnt << " ";
        ans = std::min(cnt, ans);
    } 
    std::cout << ans << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);


    int t = 1;
    // std::cin >> t;

    while (t--) {
        solve();
    }

}