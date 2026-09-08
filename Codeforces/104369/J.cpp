#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    map<int, array<int, 2>> mp;
    for (int i = 0; i < n; i ++ ) {
        for (int j = 0; j < m; j ++ ) {
            cin >> a[i][j];
            mp[a[i][j]] = {i, j};
        }
    }
    set<array<int, 4>> s;
    s.insert({0, n - 1, 0, m - 1});
    for (auto [p, v] : mp) {
        auto [x, y] = v;
        auto it = s.lower_bound({x, x, y, y});
        if (it != s.end()) {
            auto [a, b, c, d] = *it;
            if (a != x || y < c || y > d) {
                // cout << p << endl;
                it--;
            }
        } else {
            it--;
        }
        // auto t = prev(it);
        auto [a, b, c, d] = *it;
        // cout << a << " " << b << " " << c << " " << d << endl;
        // cout << x << " " << y << endl;
        if (x >= a && x <= b && y >= c && y <= d) {
            s.extract(it);
            s.insert({a, x, c, y});
            // cout << a << " " << x << " " << c << " " << y << endl;
            s.insert({x, b, y, d});
            // cout << x << " " << b << " " << y << " " << d << endl;
        } else {
            cout << p << endl;
            return;
        }
    }
    cout << n * m << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T -- ) {
        solve();
    }

    return 0;
}