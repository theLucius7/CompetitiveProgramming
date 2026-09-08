#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
const int inf = 1e18;
int n, m;
int a[N];
int l[N],r[N];
vector<int> mp[N];
int bb[N];
int dp[N];

struct Node {
    int l, r;
    int Min;
}t[N * 4];

void pushup(int p) {
    t[p].Min = min(t[p << 1].Min, t[p << 1 | 1].Min);
}

void build(int p, int l, int r) {
    t[p] = {l, r, inf};
    if (l != r) {
        int mid = l + r >> 1;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
    }
}

void modify(int p, int l, int r, int x, int v) {
    if (l == x && r == x) {
        t[p].Min = v;
    } else {
        int mid = l + r >> 1;
        if (x <= mid) {
            modify(p << 1, l, mid, x, v);
        } else {
            modify(p << 1 | 1, mid + 1, r, x, v);
        }
        pushup(p);
    }
}

int query(int p, int l, int r, int x, int y) {
    if (l >= x && r <= y) {
        return t[p].Min;
    } else {
        int mid = l + r >> 1;
        int res = inf;
        if (x <= mid) {
            res = min(res, query(p << 1, l, mid, x, y));
        } else {
            res = min(res, query(p << 1 | 1, mid + 1, r, x, y));
        }
        return res;
    }
}

void solve() {
    cin >> n;
    for(int i = 1 ; i<= n ; i++){
        cin >> a[i];
        dp[i] = 1e18;
        bb[i]  =1e18;
        mp[i].clear();
    }
    cin >> m;

    for(int i = 1 ; i<= m ; i++){
        cin >> l[i] >> r[i];
        mp[r[i]].push_back(l[i]);
    }
    for(int i = 1 ; i <= n; i++){
        if(!mp[i].size()){
            sort(mp[i].begin(),mp[i].end(),greater<int>());
        }
    }
    int rr = 0;

    for(int i = 1 ; i<= n; i++){
        if(!mp[i-1].empty() && mp[i].size()){
            rr = max(rr,mp[i-1][0]);
        }
        bb[i] =  rr;
        // cout << bb[i] << "\n";
    }
    build(1,0,n);
    modify(1, 0, n, 0, 0);
    for(int i = 1 ; i<= n; i++){
        int t = query(1,0,n,bb[i],i-1);
        dp[i] = min(dp[i],a[i] + query(1,0,n,bb[i],i-1));
        modify(1,0,n,i,dp[i]);
        // cout << i << " " << bb[i] << " " << a[i] << " " << t << " " << dp[i] << endl;
        // cout << dp[i] << endl;
    }
    cout << dp[n] << "\n";
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