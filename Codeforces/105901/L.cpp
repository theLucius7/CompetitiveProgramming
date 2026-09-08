#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve(){
    int n;
    cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    // if (n == 2 && a[0] == a[1]) {
    //     std::cout << 2 << "\n";
    //     return;
    // }

    std::sort(a.begin(), a.end());

    std::map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[a[i]] = i;
    }

    int ans = 1;
    for (int m = 0; m < n; m++) {
        for (int l = 0; l <= m; l++) {
            
            if (mp.contains(2 * a[m] - a[l])) {
                int r = mp[2 * a[m] - a[l]];
                int min = std::min(r - m, m - l);
                int res = 1 + min * 2;

            
                // if ((r - m) * 2 + 1 <= ans) {
                //     break;
                // }

                if (r - m > min) {
                    res++;
                }
                ans = std::max(ans, res);
            }
        }
    }
    std::cout << ans << "\n";

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