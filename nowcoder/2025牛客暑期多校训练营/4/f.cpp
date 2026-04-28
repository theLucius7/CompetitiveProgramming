#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, c;
    cin >> n >> k >> c;

    vector<int> a(n);
    for (int &x : a) cin >> x;

    // 初始前 k 个的总价值
    i64 res = 0;
    priority_queue<pii, vector<pii>, greater<>> pq; // 小根堆，存 (值, 位置)

    for (int i = 0; i < k; ++i) {
        pq.emplace(a[i], i);
        res += a[i];
    }

    i64 ans = res;

    for (int i = k; i < n; ++i) {
        auto [val, pos] = pq.top();

        i64 cost = 1LL * (i - pos) * c;
        i64 delta = 1LL * a[i] - val - cost;

        if (delta > 0) {
            // 替换
            pq.pop();
            pq.emplace(a[i], i);
            res += delta;
            ans = max(ans, res);
        }
    }

    cout << ans << '\n';
    return 0;
}
