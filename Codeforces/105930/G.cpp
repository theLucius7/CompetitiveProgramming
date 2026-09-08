#include <bits/stdc++.h>
#define int long long
using namespace std;

using i64 = long long;
const int N = 2e5+10;
int a[N];
void solve() {
    int n,k;
    cin >> n >> k;
    for(int i = 1 ; i<= n ; i++){
        int w,t;
        cin >> w >> t;
        a[i] = k - w + t;
    }
    sort(a+1,a+1+n);
    
    for(int i = 1 ; i<= n ; i++){
        a[i] = max(a[i],a[i-1] + 1);
        
    }
    cout << a[n] << "\n";

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }


    return 0;
}