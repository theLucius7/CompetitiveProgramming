#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    std::set<int> s;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        s.insert(a[i]);
    }

    int cnt = 0;
    std::vector<int> v;
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            cnt++;
            v.push_back(i - 1);
            v.push_back(i);
        }
    }

    v.erase(std::unique(v.begin(), v.end()), v.end());

    if (cnt == s.size() - 1) {
        std::cout << "YES\n";
        return;
    }

    if (cnt > s.size() + 4) {
        std::cout << "NO\n";
        return;
    }
    std::map<std::pair<int, int>, bool> vis;
    for (auto x : v) {
        for (int y = 0; y < n; y++) {
            if (x == y || vis[{std::min(x, y), std::max(x, y)}]) {
                continue;
            }


            int d = 0;

            if (x + 1 == y) {
                d += (x - 1 >= 0) ? ((a[y] != a[x - 1]) - (a[x] != a[x - 1])) : 0;
                d += (y + 1 < n) ? ((a[x] != a[y + 1]) - (a[y] != a[y + 1])) : 0;
            } else if (y + 1 == x) {
                d += (y - 1 >= 0) ? ((a[x] != a[y - 1]) - (a[y] != a[y - 1])) : 0;
                d += (x + 1 < n) ? ((a[y] != a[x + 1]) - (a[x] != a[x + 1])) : 0;
            } else {
                if (x - 1 >= 0) {
                    d += (a[y] != a[x - 1]) - (a[x] != a[x - 1]);
                }
                if (x + 1 < n) {
                    d += (a[y] != a[x + 1]) - (a[x] != a[x + 1]);
                }
                if (y - 1 >= 0) {
                    d += (a[x] != a[y - 1]) - (a[y] != a[y - 1]);
                }
                if (y + 1 < n) {
                    d += (a[x] != a[y + 1]) - (a[y] != a[y + 1]);
                }
            }

            if (cnt + d == s.size() - 1) {
                // std::cout << cnt << / " " << d << " " << s.size() << "///";
                // std::cout << x << " " << y << "\n";
                std::cout << "YES\n";
                
                return;
            }

            vis[{std::min(x, y), std::max(x, y)}] = true;
            
        }
    }
    std::cout << "NO\n";
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
