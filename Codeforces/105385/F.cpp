#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using i64 = long long;

using namespace std;
const int N = 5e5+10;
int a[N];
void solve() {
    int n;
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    a[n+1] = 0;
    for(int i = n ; i >= 1 ;i--){
        a[i] += a[i+1];
        // cout << a[i] << " \n"[i == 1];
    }
    sort(a+2,a+n + 1);
    int ans = a[1];
    cout << ans << " ";
    for(int i = n ; i >= 2; i--){
        ans += a[i];
        cout << ans << " ";
    }
    cout << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T -- ) {
        solve();
    }

    return 0;
}