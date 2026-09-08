#include <bits/stdc++.h>

using i64 = long long;
using namespace std;

#define int long long

const int inf = 2e9;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<array<int, 3>> e(m);
    for (int i = 0; i < m; i ++ ) {
        cin >> e[i][0] >> e[i][1] >> e[i][2];
        e[i][0] -- ;
        e[i][1] -- ;
    }
    vector<vector<array<int, 2>>> qur(n);
    for (int i = 0; i < q; i ++ ) {
        int u, d;
        cin >> u >> d;
        u -- ;
        qur[u].push_back({d, i});
    }
    for (int i = 0; i < n; i ++ ) {
        sort(qur[i].begin(), qur[i].end(), greater<>());
    }
    vector<int> d(n, 1);
    vector<int> f(n, 1);
    vector<int> ans(q);
    for (int i = 1; i <= 30; i ++ ) {
        for (auto [u, v, w] : e) {
            d[u] = max(d[u], min(f[v] * w, inf));
            while (qur[u].size() && qur[u].back()[0] < d[u]) {
                // cout << i << " " <
                ans[qur[u].back()[1]] = i;
                qur[u].pop_back();
            }
        }
        swap(d, f);
    }
    for (int i = 0; i < n; i ++ ) {
        // cout << f[i] << " \n"[i == n - 1];
    }
    for (int i = 0; i < q; i ++ ) {
        cout << ans[i] << endl;
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

}