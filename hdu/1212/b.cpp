#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using i64 = long long;

using namespace std;

const int N = 4e5 + 10;

struct DSU {
    std::vector<int> f, siz;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        // std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};

void solve() {
    int n, m;
    vector<int> a(N);
    map<int, int> pos;
    cin >> n;
    
    DSU dsu(N);
    vector<int> st(N);
    int cnt = 0;
    for (int i = 1; i <= n; i ++ ) {
        cin >> a[i];
        if (!pos[a[i]]) {
            dsu.f[i] = i;
        } else {
            dsu.merge(i, pos[a[i]]);
        }
        pos[a[i]] = i;
        st[i] = 1;
    }
    cin >> m;
    for (int i = n + 1; i <= n + m; i ++ ) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, y;
            cin >> x >> y;
            // cout << x << " " << y << " " << pos[x] << " " << pos[y] << endl;
            if (!dsu.same(0, pos[y])) {
                dsu.merge(pos[y], pos[x]);
            } else {
            	pos[y] = i;
            	a[i] = y;
            	dsu.f[i] = i;
            	dsu.merge(pos[y], pos[x]);
            }
            pos[x] = 0;
        } else if (op == 2) {
        	st[i] = 1;
            int x;
            cin >> x;
            a[i] = x;
            if (dsu.same(0, pos[x])) {
                dsu.f[i] = i;
            } else {
                dsu.merge(pos[x], i);
            }
            pos[x] = i;
        } else {
            int x;
            cin >> x;
            dsu.merge(0, pos[x]);
            pos[x] = 0;
        }
    }
    for (int i = 1; i <= n + m; i ++ ) {
        int t = dsu.find(i);
        // cout << i << " " << t << endl;
        if (t && st[i]) {
            cout << a[t] << " ";
        }
    }
    cout << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T -- ) {
        solve();
    }

    return 0;
}