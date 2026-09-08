#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;
    vector<array<int, 2>> v(n + 1), l(n + 1);
    vector<int> vv(n + 1), ll(n + 1);
    int vsum = 0, lsum = 0;
    for (int i = 1; i <= n; i ++ ) {
        cin >> v[i][0];
        v[i][1] = i;
        vv[i] = v[i][0];
        vsum += v[i][0];
    }
    for (int i = 1; i <= n; i ++ ) {
        cin >> l[i][0];
        l[i][1] = i;
        ll[i] = l[i][0];
        lsum += l[i][0];
    }
    // cout << vsum << " " << lsum << endl;
    sort(v.begin() + 1, v.end());
    sort(l.begin() + 1, l.end(), [&](array<int, 2> x, array<int, 2> y) {
        return x[0] > y[0];
    });
    int qq;
    cin >> qq;
    vector<array<int, 2>> qur(qq + 1);
    for (int i = 1; i <= qq; i ++ ) {
        cin >> qur[i][0];
        qur[i][1] = i;
    }
    vector<int> ans(qq + 1);
    sort(qur.begin() + 1, qur.end());
    vector<int> st(n + 1);
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
    for (int i = 1, x = 1, y = 1, lst = 0; i <= qq; i ++ ) {
        auto [t, id] = qur[i];
        while (pq.size() && pq.top()[0] <= t) {
            auto [_, V, L] = pq.top();
            pq.pop();
            vsum += L * lst;
            vsum -= V;
            lsum -= L;
        }
        while (true) {
            while (x <= n && st[v[x][1]]) {
                x ++ ;
            }
            while (y <= n && st[l[y][1]]) {
                y ++ ;
            }
            if (x > n || y > n) {
                break;
            }
            // cout << "666 " << i << " " << x << " " << y << " " << v[x][1] << " " << l[y][1] << endl;
            if (v[x][0] >= t * l[y][0]) {
                // cout << i << " " << x << " " << y << " " << v[x][1] << " " << l[y][1] << endl;
                // vsum -= (t - lst) * lsum;
                break;
            }
            int p = v[x][1], q = l[y][1];
            // cout << p << " " << q << endl;
            st[p] = st[q] = 1;
            vsum += max(ll[p], ll[q]) * lst;
            vsum -= min(vv[p], vv[q]);
            // vsum -= min(ll[p], ll[q]) * (t - lst);
            // cout << "000 " << p << " " << q << " " << ll[p] << " " << ll[q] << endl;
            lsum -= max(ll[p], ll[q]);
            if (p != q && min(ll[p], ll[q]) > 0) {
                pq.push({max(vv[p], vv[q]) / min(ll[p], ll[q]) + 1, max(vv[p], vv[q]), min(ll[p], ll[q])});
            }
            x ++ , y ++ ;
        }
        while (pq.size() && pq.top()[0] <= t) {
            auto [_, V, L] = pq.top();
            pq.pop();
            vsum += L * lst;
            vsum -= V;
            lsum -= L;
        }
        // cout << i << " " << lsum << endl;
        vsum -= (t - lst) * lsum;
        lst = t;
        ans[id] = vsum;
    }
    for (int i = 1; i <= qq; i ++ ) {
        cout << ans[i] << " \n"[i == qq];
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T -- ) {
        solve();
    }

    return 0;
}
