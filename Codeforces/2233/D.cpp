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
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            cnt++;
        }
    }

    std::map<int, std::vector<std::pair<int, int>>> mp;
    for (int l = 0, r = 0; l < n; l = r) {
        while (r < n && a[l] == a[r]) {
            r++;
        }
        mp[a[l]].push_back({l, r - 1});
    }

    int mx = 0;
    std::vector<int> vec;
    for (auto [k, v] : mp) {
        if (v.size() > 4) {
            std::cout << "NO\n";
            return;
        }
        
        if (v.size() > mx) {
            mx = v.size();
            vec.clear();
            for (int i = 0; i < v.size(); i++) {
                vec.push_back(std::max(0LL, v[i].first - 1));
                vec.push_back(v[i].first);
                vec.push_back(v[i].second);
                vec.push_back(std::min(n - 1, v[i].second + 1));
            }
        }

    }

    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());

    if (cnt == s.size() - 1) {
        std::cout << "YES\n";
        return;
    }

    for (auto x : vec) {
        for (int y = 0; y < n; y++) {
            if (x == y) {
                continue;
            }

            int d = 0;

            if (x + 1 == y) {
                d += x - 1 >= 0 ? (a[y] != a[x - 1]) - (a[x] != a[x - 1]) : 0;
                d += y + 1 < n ? (a[x] != a[y + 1]) - (a[y] != a[y + 1]) : 0;
            } else if (y + 1 == x) {
                d += y - 1 >= 0 ? (a[x] != a[y - 1]) - (a[y] != a[y - 1]) : 0;
                d += x + 1 < n ? (a[y] != a[x + 1]) - (a[x] != a[x + 1]) : 0;
            } else {
                d += x - 1 >= 0 ? (a[y] != a[x - 1]) - (a[x] != a[x - 1]) : 0;
                d += x + 1 < n ? (a[y] != a[x + 1]) - (a[x] != a[x + 1]) : 0;
                d += y - 1 >= 0 ? (a[x] != a[y - 1]) - (a[y] != a[y - 1]) : 0;
                d += y + 1 < n ? (a[x] != a[y + 1]) - (a[y] != a[y + 1]) : 0;
            }

            if (cnt + d == s.size() - 1) {
                std::cout << "YES\n";
                return;
            }
            
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
