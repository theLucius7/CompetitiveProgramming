#include <bits/stdc++.h>
#define int long long
using namespace std;

using i64 = long long;

struct DSU {
    vector<int> f;

    DSU(int n) {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
    }

    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        f[y] = x;
        return true;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<array<int, 4>> e(m);
    for (int i = 0; i < m; i ++ ) {
        cin >> e[i][1] >> e[i][2] >> e[i][0];
        e[i][1] -- , e[i][2] -- ;
        e[i][3] = i + 1;
    }

    sort(e.begin(), e.end());
    DSU dsu(n);
    int cnt = n;
    int sum = 0;
    vector<int> ans;
    for (auto [w, x, y, i] : e) {
        if (cnt - 1 <= k && w > 0) {
            break;
        }
        if (dsu.merge(x, y)) {
            // cout << "000 " << x + 1 << " " << y + 1 << endl;
            cnt -- ;
            sum += w;
            ans.push_back(i);
        }
    }
    cout << cnt - 1 << endl;
    for (int i = 0; i + 1 < n; i ++ ) {
        if (dsu.merge(i, i + 1)) {
            cout << i + 1 << " " << i + 2 << endl;
        }
    }
    // cout << endl;
    cout << sum + cnt - 1 << endl;
    for (auto i : ans) {
        cout << i << " ";
    }
    for (int i = 1; i <= cnt - 1; i ++ ) {
        cout << m + i << " ";
    }
    cout << endl;
}   

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }


    return 0;
}