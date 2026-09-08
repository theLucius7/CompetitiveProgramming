#include <bits/stdc++.h>

using i64 = long long;

using namespace std;


void solve() {
    int n, k, m;
    std::cin >> n >> k >> m;

    std::vector<int> cnt(k);
    std::vector<int> ans(n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] -- ;
        cnt[a[i]] ++ ;
    }
    vector<int> st(k);
    for (int i = 0; i < n; i ++ ) {
        if (cnt[a[i]] & 1) {
            if (st[a[i]]) {
                ans[i] = m / (n * 2) + (m % (n * 2) >= i + 1);
            } else {
                ans[i] = m / (n * 2) + (m % (n * 2) >= n + i + 1);
            }
        } else {
            if (st[a[i]]) {
                ans[i] = m / n + (m % n >= i + 1);
            } else {
                ans[i] = 0;
            }
        }
        st[a[i]] ^= 1;
    }

    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << " \n"[i == n - 1];
    }

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}