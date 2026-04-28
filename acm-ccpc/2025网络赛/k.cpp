#include <bits/stdc++.h>
#define int long long

using i64 = long long;

using namespace std;



void solve(){
    int n  ;
    cin >> n ;
    cout << n * (n + 1) / 2 << '\n';
    for(int i = n ; i >= 1; -- i ) cout << i << ' ';
    // vector<int> ans( 2 * n);
    // for (int i = 0; i < 2 * n; i++) {
    //     ans[i] = (i) % n + 1;
    // }
    // vector<int> fa(n + 1 );
    // function<int(int)> find = [&](int x ) {
    //     if(x != fa[x]) return fa[x] = find(fa[x]);
    //     return x;
    // };
    // auto merge = [&](int a, int b){
    //     fa[find(a)] = find(b);
    // };
    // std::reverse(ans.begin(), ans.end());
    // int res=  0;
    // for(int i = 0 ; i < n; ++ i ) {
    //     int l = i ;
    //     int r = i + n - 1;
    //     iota(fa.begin(), fa.end() , 0);
    //     for(int p = l ;p <= r; ++ p){
    //         merge(p - l + 1, ans[p]);
    //     }
    //     set<int> s;
    //     for(int p = 1; p <= n; ++ p) {
    //         s.insert(find(p));
    //     }
    //     res += s.size();
    // } 
    // cout << res << '\n';
    // for(int i = n ; i >= 1; -- i ) cout << i << ' ';
    // cout << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while(_--){
        solve();
    }
    
    return 0;
}