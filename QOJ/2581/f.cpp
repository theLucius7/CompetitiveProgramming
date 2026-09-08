#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
using i64 = long long;

struct DSU {
    std::vector<int> f, siz;

    DSU() {}
    DSU(int n) {
        init(n);
    }

    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
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
    int n, q;
    std::cin >> n >> q;

    std::vector<DSU> dsu(5E3 + 10, DSU(n));
    i64 ans = 0;

    auto dfs = [&](auto self, int x, int id, int u, int v) -> void {
        if (id < -1) {
            return;
        }


        bool flag = dsu[x].same(u, v);
        dsu[x].merge(u, v);

        int nid = id;
        while (nid >= 0 && (!((x >> nid) & 1))) {
            nid--;
        }

        if (nid < 0) {
            return;
        }

        int y = x - (1 << nid);
        self(self, y, nid - 1, u, v);
        if (!flag) {
            self(self, x, nid - 1, u, v);
        }
    };


    for (int t = 0; t < q; t++) {
        char op;
        std::cin >> op;
        if (op == '+') {
            int x, y, w;
            std::cin >> x >> y >> w;
            x--, y--;
            dfs(dfs, w, 11, x, y);
            // std::cout << x << " " << y << " " << w << "\n";
            // for (int i = 0; i <= w; i++) {
            //     if ((i & w) == i) {
            //         // std::cout << "i: " <<  i << "\n";
            //         dsu[i].merge(x, y);
            //     }
            // }
        } else {
            int x, y;
            std::cin >> x >> y;
            x--, y--;

            bool ok = dsu[0].same(x, y);
            int cur = 0;
            int id = 11;
            for (int i = id; id >= 0; id--) {
                if (dsu[cur + (1 << id)].same(x, y)) {
                    ok = true;
                    cur += (1 << id);
                }
            }
            // cout << cur << endl;
            ans += cur;
    
            if (!ok) {
                ans += -1;
                // std::cout << t << " " << "-1\n";
            }
        }
    }
    std::cout << ans << "\n";
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

