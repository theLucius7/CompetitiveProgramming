#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using i64 = long long;

using namespace std;

const int mod = 998244353;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; i ++ ) {
        cin >> a[i][0] >> a[i][1];
    }
    sort(a.begin(), a.end());
    int ans = 1;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i ++ ) {
        while (pq.size() && pq.top() < a[i][0]) {
            pq.pop();
        }
        // cout << pq.size() << " \n"[i == n - 1];
        ans = ans * (k - pq.size()) % mod;
        pq.push(a[i][1]);
    }
    cout << ans << endl;
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