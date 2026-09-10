#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve(){
    int n;
    cin >> n;
    
    std::vector<std::pair<int, int>> p(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i].first >> p[i].second;
    }

    std::map<std::pair<int, std::vector<std::pair<int, int>>>, bool> mp;
    auto dfs = [&](auto self, int c, std::vector<std::pair<int, int>> &p) -> bool {
        if (p.empty()) {
            return false;
        }
        if (mp.contains({c, p})) {
            return mp[{c, p}];
        }

        bool ok = false;
        for (int i = 0; i < p.size(); i++) {
            std::vector<std::pair<int, int>> np;
            for (int j = 0; j < p.size(); j++) {
                auto [u, v] = p[j];
                if (j == i) {
                    if (c == 0) {
                        u--;
                    } else {
                        v--;
                    }
                }
                if (u > 0 && v > 0) {
                    np.push_back({u, v});
                }
            }
            auto f = self(self, !c, np);
            if (f == false) {
                ok = true;
                break;
            }
        }
        return mp[{c, p}] = ok;
    };

    dfs(dfs, 0, p);

    std::cout << (mp[{0, p}] ? "Alice" : "Bob") << "\n";
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();

    return 0;
}