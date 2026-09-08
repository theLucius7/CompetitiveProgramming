#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5+10;
int a[N],b[N];
bool cmp(array<int,2> x,array<int,2> y){
    if(x[0] == y[0]){
        return x[1] < y[1];
    }
    return x[0] < y[0];
}
void solve() {
    int n;
    cin >> n;
    vector<array<int,2>> v;
    for(int i = 1 ; i<= n ; i++){
        cin >> a[i] >> b[i];
        v.push_back({a[i],b[i]});
    }
    sort(v.begin(),v.end(),cmp);
    int l = 0,r = n-1;
    int ans = 0;
    while(l < r){
        if(v[l][0] >= v[r][0]) break;
        if(v[l][1] >= v[r][1]){
            ans += (v[r][0] - v[l][0]) * v[r][1];
            v[l][1]-=v[r][1];
            r--;
        }else{
            ans += (v[r][0] - v[l][0]) * v[l][1];
            v[r][1]-=v[l][1];
            l++;
        }
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