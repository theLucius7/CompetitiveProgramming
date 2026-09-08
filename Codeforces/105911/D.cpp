#include <bits/stdc++.h>

using i64 = long long;
using namespace std;

#define int long long

void solve() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<array<int, 6>> p(n);
    vector<vector<int>> v(3);                                                               
    for (int i = 0; i < n; i ++ ) {
        for (int j = 0; j < 6; j ++ ) {
            cin >> p[i][j];
            v[j % 3].push_back(p[i][j]);
        }
    }
    int siz[3]{};
    vector<vector<int>> s(3);
    for (int i = 0; i < 3; i ++ ) {
        v[i].push_back(-1);
        sort(v[i].begin(), v[i].end());
        v[i].erase(unique(v[i].begin(), v[i].end()), v[i].end());
        siz[i] = v[i].size() + 1;
        s[i].resize(siz[i] + 1);
        for (int j = 0; j < n; j ++ ) {
            // cout << i << " " << j << " " << p[j][i] << " " << p[j][i + 3] << endl;
            p[j][i] = lower_bound(v[i].begin(), v[i].end(), p[j][i]) - v[i].begin();
            p[j][i + 3] = lower_bound(v[i].begin(), v[i].end(), p[j][i + 3]) - v[i].begin();
            // cout << i << " " << j << " " << p[j][i] << " " << p[j][i + 3] << endl;
            int l = min(p[j][i], p[j][i + 3]);
            int r = max(p[j][i], p[j][i + 3]);
            s[i][l] ++ ;
            s[i][r + 1] -- ;
        }
    }
    int ans = 0;
    for (int i = 0; i < 3; i ++ ) {
        for (int j = 1; j < s[i].size(); j ++ ) {
            s[i][j] += s[i][j - 1];
            ans = max(ans, s[i][j]);
            // cout << s[i][j] << " \n"[j == s[i].size() - 1];
        }
    }
    cout << ans << endl;
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