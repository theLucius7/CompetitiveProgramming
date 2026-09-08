#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 109;
int n,q;
int a[N];
int dp[N][2];
void solve(){
    cin >> n >> q;
    for(int i = 1 ; i<= n ; i ++){
        cin >> a[i];
        dp[i][0] = -1;
        dp[i][1] = 1e18;
    }
    bool f = true;
    while(q--){
        int p,l,r;
        cin >> p >> l >> r;
        if(!f) continue;
        if (dp[p][0] > r || dp[p][1] < l) {
            f = false;
        }
        dp[p][0] = max(dp[p][0],l);
        dp[p][1] = min(dp[p][1],r);
    }
    if(!f){
        cout << -1 << "\n";
    }else{
        int ans = 0;
        for(int i = 1 ; i<= n ;i++){
    
            if(dp[i][0] <= a[i] && a[i] <= dp[i][1]){
                continue;
            }else{
                ans += min(abs(a[i] - dp[i][0]),abs(a[i] - dp[i][1]));
            }
        }
        cout << ans << "\n";
    }

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