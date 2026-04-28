#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        vector<ll> a(n + 1);
        multiset<ll> s;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            s.insert(a[i]);
        }
        int need = (n - 1 + 1) / 2;

        auto calc = [&]() {
            int cnt = 0;
            for (int i = 1; i <= n; i++) {
                int big = distance(s.upper_bound(a[i]), s.end());
                if (big >= need) cnt++;
            }
            return cnt;
        };

        while (q--) {
            int idx;
            ll x;
            cin >> idx >> x;
            s.erase(s.find(a[idx]));
            a[idx] += x;
            s.insert(a[idx]);
            cout << calc() << '\n';
        }
    }
}
