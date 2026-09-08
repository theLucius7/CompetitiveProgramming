#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 5e5+10;
int a[N],b[N];
int pr[N],en[N];
void solve() {
    int n,m;
    int ans = 0;
    cin >> n >> m;
    vector<array<int,2>> v;
    for(int i = 1 ; i<= n ; i++){
        cin >> a[i] >> b[i];
        v.push_back({b[i] - a[i],i});
    }
    sort(v.begin(),v.end());
    if(n == 1){
        cout << b[1] << "\n";
        return ;
    }
    if(n == m){
        for(int i = 1 ; i<= n ; i++){
            ans += a[i];
        }
        cout << ans << "\n";
        return ;
    }
    for(int i = 0 ; i < n ; i++){
        if(i == 0){
            pr[1] = a[v[i][1]];
        }else{
            pr[i+1] = pr[i] + a[v[i][1]];
        }
    }
    int id = 0;
    for(int i = n-1 ; i>= 0 ;i--){
        en[id+1] = en[id] + b[v[i][1]];
        id++;
    }
    if(m >= 2*n-1){
        for(int i = 1 ; i<= n; i++){
            ans += b[i];
        }
    }
    for(int i = 2 ; i<= n ; i++){
        int r = n - i;
        if(m - i <2* r){
            continue;
        }
        int res = pr[i] + en[r];
        ans = max(ans,res);
    }
    cout << ans << "\n";
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