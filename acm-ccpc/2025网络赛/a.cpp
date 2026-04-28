#include <bits/stdc++.h>
#define int long long

using i64 = long long;

using namespace std;

vector<int> dx = {1,1,-1,-1};
vector<int> dy = {1,-1,-1,1};

void solve(){
    int n , m;
    cin >> n >> m;
    for (int i = 0; i <= n; i ++ ) {
        for (int j = 0; j <= m; j ++ ) {
            int ans = 0;
            ans += min(i, j) + min(i, m - j) + min(n - i, j) + min(n - i, m - j);
            //cout << ans << " \n"[j == m];
            if (j - 1 >= 1 && n - i >= 1) {
                int x = i, y = j;
                if (y - 1 <= n - x) {
                    int t = min(y - 1, x);
                    ans += t * (2 * (y - 1) - t + 1) / 2;
                } else {
                    int a = max(y - 1, n - x);
                    int b = min(y - 1, n - x);
                    ans += min(x, a - b) * b;
                    x -= min(x, a - b);
                    x = max(x, 0ll);
                    x = min(x, b);
                    ans += x * (2 * b - x + 1) / 2;
                }
            }
            //cout << ans << " \n"[j == m];
            if (m - j - 1 >= 1 && n - i >= 1) {
                int x = i, y = j;
                if (m - y - 1 <= n - x) {
                    int t = min(m - y - 1, x);
                    ans += t * (2 * (m - y - 1) - t + 1) / 2;
                } else {
                    int a = max(m - y - 1, n - x);
                    int b = min(m - y - 1, n - x);
                    ans += min(x, a - b) * b;
                    x -= min(x, a - b);
                    x = max(x, 0ll);
                    x = min(x, b);
                    ans += x * (2 * b - x + 1) / 2;
                }
            }
            //cout << ans << " \n"[j == m];
            if (i - 1 >= 1 && m - j >= 1) {
                int x = i, y = j;
                if (x - 1 <= m - y) {
                    int t = min(x - 1, y);
                    ans += t * (2 * (x - 1) - t + 1) / 2;
                } else {
                    int a = max(x - 1, m - y);
                    int b = min(x - 1, m - y);
                    ans += min(y, a - b) * b;
                    y -= min(y, a - b);
                    y = max(y, 0ll);
                    y = min(y, b);
                    ans += y * (2 * b - y + 1) / 2;
                }
            }
            //cout << ans << " \n"[j == m];
            if (n - i - 1 >= 1 && m - j >= 1) {
                int x = i, y = j;
                if (n - x - 1 <= m - y) {
                    int t = min(n - x - 1, y);
                    ans += t * (2 * (n - x - 1) - t + 1) / 2;
                } else {
                    int a = max(n - x - 1, m - y);
                    int b = min(n - x - 1, m - y);
                    ans += min(y, a - b) * b;
                    y -= min(y, a - b);
                    y = max(y, 0ll);
                    y = min(y, b);
                    ans += y * (2 * b - y + 1) / 2;
                }
            }
            cout << ans << " \n"[j == m];
        }
    }

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