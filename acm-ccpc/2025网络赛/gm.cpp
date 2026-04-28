#include <bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using namespace std;

typedef pair<int,int> PII;

void solve(){
    int n , q;
    cin >> n >> q;
    vector<int> a(n ) ;
    for(int i = 0 ; i < n; ++ i ) cin >> a[i];
    vector<PII> query(q);
    for(int i = 0 ; i < q; ++ i ) cin >> query[i].first >> query[i].second;
    map<PII,int> ans;
    map<int,int> cnt;
    set<int> l, r;
    for(int i = n - 1; i >= 0; -- i ) {
        int val = a[i];
        if(l.contains(val)){
            ans[{}]
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while(_ --){
        solve();
    }
    

    return 0;
}