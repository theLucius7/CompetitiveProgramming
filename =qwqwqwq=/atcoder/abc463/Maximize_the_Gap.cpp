#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int N, K;
    std::cin >> N >> K;

    std::vector<std::pair<int, int>> a(N);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i].first >> a[i].second;
    }

    std::sort(a.begin(), a.end(), [&](auto x, auto y) {
        if (x.second != y.second) {
            return x.second < y.second;
        } else {
            return x.first < y.first;
        }
    });

    constexpr int inf = 1E18;

    auto check = [&](int m) {
        int cnt = 0;
        int r = -inf;
        for (int i = 0; i < N; i++) {
            if (a[i].first - r >= m) {
                cnt++;
                if (cnt == K) {
                    return true;
                }
                r = a[i].second;
            }
        }
        return false;
    };  

    int lo = 0, hi = 1E9 + 10;
    while (lo < hi) {
        int m = (lo + hi + 1) / 2;
        if (check(m)) {
            lo = m;
        } else {
            hi = m - 1;
        }
    }

    std::cout << (lo == 0 ? -1 : lo) << "\n";

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
