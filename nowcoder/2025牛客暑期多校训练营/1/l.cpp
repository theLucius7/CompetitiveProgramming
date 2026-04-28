#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, q;
    std::cin >> n >> q;

    std::multiset<i64> S;

    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        S.insert(a[i]);
    }

    while(q--) {
        int p, v;
        std::cin >> p >> v;

        S.erase(S.find(a[p - 1]));
        a[p - 1] += v;
        S.insert(a[p - 1]);

        int cnt = 0;
        i64 last = -1;
        for (auto it = S.rbegin(); it != S.rend(); it++) {
            if(last == -1) {
                cnt++;
                last = *it;
            } else if (*it == last) {
                cnt++;
            } else {
                if (cnt >= n / 2) {
                    break;
                }
                cnt++;
                last = *it;
            }
        }
        std::cout << n - cnt << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }


    return 0;
}
