#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve(){
    int n, k;
    std::cin >> n >> k;

    if (n == 1 && k == 1) {
        std::cout << "Yes\n";
        std::cout << 1 << "\n";
        return;
    }

    std::vector<bool> vis(n * n + 1);
    std::vector ans(n, std::vector<int> (n));

    if (k > n - 1 && k <=  n * n - n + 1) {
        std::cout << "Yes\n";
        vis[k] = true;
        ans[0][0] = k;
        for (int i = 1; i < n; i++) {
            ans[0][i] = i;
            vis[i] = true;
        }
        for (int i = 1; i < n; i++) {
            ans[i][i] = k + i;
            vis[k + i] = true;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!ans[i][j]) {
                    for (int x = 1; x <= n * n; x++) {
                        if (!vis[x]) {
                            ans[i][j] = x;
                            vis[x] = true;
                            break;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << ans[i][j] << " \n"[j == n - 1];
            }
        }

    } else {
        std::cout << "No\n";
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