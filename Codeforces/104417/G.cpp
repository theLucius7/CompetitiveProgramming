#include <bits/stdc++.h>
#define int long long
using i64 = long long;

using namespace std;

void solve() {
    int n;
    std::cin >> n;

    std::map<int, std::vector<int>> map;

    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        map[i + 1 - a].push_back(a);
    }

    int ans = 0;
    for (auto [x, v] : map) {
        if (v.size() <= 1) {
            continue;
        }

       std::sort(v.begin(), v.end(), std::greater<int>());

       for (int i = 0; i + 1 < v.size(); i += 2) {
        if (v[i] + v[i + 1] > 0) {
            ans += v[i] + v[i + 1];
        } else {
            break;
        }
       }
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