#include <bits/stdc++.h>

using i64 = long long;

#define int long long

using namespace std;
const int N = 1e5+10;
int n, k,x;
int s[N],t[N],p[N];
bool check(int v){
    int len = 0;
    int tt= 0 ;
    for(int i = 0 ; i<= k ; i++){
        if(x - len <= (p[i] - t[i]) * v){
            return true;
        }
    }
    return false;
}
void solve() {
    cin >> n >> k >> x >> p[0];
    for(int i = 1 ; i<= n ; i++){
        cin >> s[i];
    }
    for(int i = 1 ; i<= k ; i++){
        cin >> t[i];
    }
    for(int i = 1 ; i<= k ; i++){
        cin >> p[i];
    }
    int l = 1,r = 1e9,mid;
    int ss = 0;
    while(l <= r){
        mid = (l + r) / 2;
        if(check(mid)){
            r = mid-1;
            ss = mid;

        }else{
            l = mid+1;
        }
    }
    int ans=  0;
    for(int i = 1 ; i<= n ;i ++){
        if(ss <= s[i]){
            ans ++;
        }
    }
    cout << ans << "\n";

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}