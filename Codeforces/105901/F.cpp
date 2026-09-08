#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

const int mod = 998244353;

struct Node {
    int a, b;
    bool operator < (const Node &x) const {
        return b > x.b;
    }
};

int power(int a, int k) {
    int res = 1;
    while (k) {
        if (k & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        k >>= 1;
    }
    return res;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<Node> c(n);
    for (int i = 0; i < n; i ++ ) {
        cin >> c[i].a >> c[i].b;
    }
    sort(c.begin(), c.end());

    int x = 0, y = 0;
    int ans = 0;
    for (int i = 0; i < n; i ++ ) {
        if (x == 0) {
            int t = c[i].a / m;
            if (c[i].a % m != 0) {
                t ++ ;
                x = m - c[i].a % m;
                y = c[i].b;
            }
            ans = (ans + t * power(2, c[i].b)) % mod;
        } else {
            for (int j = 0; j < y - c[i].b; j ++ ) {
                if (x >= 2e14) {
                    cout << ans << endl;
                    return;
                }
                x *= 2;
            }
            if (x >= 2e14) {
                cout << ans << endl;
                return;
            }
            if (x >= c[i].a) {
                x -= c[i].a;
                y = c[i].b;
            } else {
                c[i].a -= x;
                x = 0;
                y = 0;
                int t = c[i].a / m;
                if (c[i].a % m != 0) {
                    t ++ ;
                    x = m - c[i].a % m;
                    y = c[i].b;
                }
                ans = (ans + t * power(2, c[i].b)) % mod;
            }
        }
    }
    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int  T ;
    cin >> T;
    while(T--){
        solve();
    }

    return 0;
}