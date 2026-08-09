#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;
    std::cin.ignore();

    std::vector<std::vector<std::string>> a(n);
    std::vector<std::vector<std::string>> tmp(n);
    for (int i = 0; i < n; i++) {
        std::string line;
        std::getline(std::cin, line);

        std::stringstream ss(line);
        std::string w;
        while (ss >> w) {
            a[i].push_back(w);
        }

        tmp[i].resize(a[i].size() + 1);
        for (int r = 0; r <= a[i].size(); r++) {
            for (int l = 0; l < a[i].size(); l++) {
                if (l < r) {
                    tmp[i][r] += a[i][l];
                    
                } else {
                    tmp[i][r].push_back(a[i][l][0]);
                }
            }
        }
    }

    std::vector<int> ans(n);
    std::map<std::string, std::vector<std::pair<int, int>>> p;
    for (int i = 0; i < n; i++) {
        p[tmp[i][0]].push_back({i, 0});
    }
    while (true) {
        std::map<std::string, std::vector<std::pair<int, int>>> np;
        for (auto [s, vec] : p) {
            if (vec.size() > 1) {
                for (auto [x, y] : vec) {
                    np[tmp[x][y + 1]].push_back({x, y + 1});
                }
            } else {
                auto [x, y] = vec.front();
                ans[x] = y;
            }
        }
        if (np.empty()) {
            break;
        }
        p = np;
    }

    for (int i = 0; i < n; i++) {
        std::cout << tmp[i][ans[i]] << "\n";
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
