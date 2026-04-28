#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    
    vector<i64> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    while (q--) {
        i64 x;
        int y;
        cin >> x >> y;

        int need_rank = n + 1 - y;

        auto check = [&](i64 t) -> bool {
            i64 score = x + t;
            // 找出大于 score 的数量
            int cnt = upper_bound(a.begin(), a.end(), score) - a.begin();
            int high = n - cnt;

            // 小明需要挑战 t 次，但最多只能挑战 score - a[i] > 0 的人
            i64 remain = t;
            for (int i = cnt; i < n && remain > 0; i++) {
                i64 d = score - a[i];
                if (d <= 0) break;
                remain -= d;
            }

            // 如果还有挑战次数，就能减少更多高分人数
            return high <= need_rank;
        };

        i64 L = 0, R = 1e10, ans = -1;
        while (L <= R) {
            i64 M = (L + R) / 2;
            if (check(M)) {
                ans = M;
                R = M - 1;
            } else {
                L = M + 1;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
