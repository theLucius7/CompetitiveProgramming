#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> V(6);
    for (int i = 0; i < n; i++) {
        int a, b, v;
        std::cin >> a >> b >> v;
        if (a > b) {
            std::swap(a, b);
        }

        if (a == 1 && b == 1) {
            V[0].push_back(v);
        } else if (a == 1 && b == 2) {
            V[1].push_back(v);
        } else if (a == 1 && b == 3) {
            V[2].push_back(v);
        } else if (a == 2 && b == 2) {
            V[3].push_back(v);
        } else if (a == 2 && b == 3) {
            V[4].push_back(v);
        } else if (a == 3 && b == 3) {
            V[5].push_back(v);
        }
    }

    std::vector<int> cost, val;
    for (int i = 0; i < 6; i++) {
        std::sort(V[i].begin(), V[i].end(), std::greater<>());
        if (i == 0) {
            for (int j = 0; j < 9 && j < V[i].size(); j++) {
                cost.push_back(1);
                val.push_back(V[i][j]);
            }
        } else if (i == 1) {
            for (int j = 0; j < 4 && j < V[i].size(); j++) {
                cost.push_back(2);
                val.push_back(V[i][j]);
            }
        } else if (i == 2) {
            for (int j = 0; j < 3 && j < V[i].size(); j++) {
                cost.push_back(3);
                val.push_back(V[i][j]);
            }
        } else if (i == 3) {
            for (int j = 0; j < 1 && j < V[i].size(); j++) {
                cost.push_back(4);
                val.push_back(V[i][j]);
            }
        } else if (i == 4) {
            for (int j = 0; j < 1 && j < V[i].size(); j++) {
                cost.push_back(6);
                val.push_back(V[i][j]);
            }
        } else {
            for (int j = 0; j < 1 && j < V[i].size(); j++) {
                cost.push_back(9);
                val.push_back(V[i][j]);
            }
        }
    }
    std::vector<int> dp(10);
    for (int i = 0; i < cost.size(); i++) {
        for (int v = 9; v >= cost[i]; v--) {
            dp[v] = std::max(dp[v], dp[v - cost[i]] + val[i]);
        }
    }

    std::cout << *std::max_element(dp.begin(), dp.end()) << "\n";
    
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
