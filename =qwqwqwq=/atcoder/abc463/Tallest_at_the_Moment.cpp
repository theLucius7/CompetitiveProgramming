#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> a(N);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i].second >> a[i].first;
    }

    std::sort(a.begin(), a.end());


    int Q;
    std::cin >> Q;
    std::vector<std::pair<int, int>> qry(Q);
    for (int i = 0; i < Q; i++) {
        std::cin >> qry[i].first;
        qry[i].second = i;
    }
    std::sort(qry.begin(), qry.end());

    std::vector<int> ans(Q);
    int mx = -1;
    for (int i = Q - 1, j = N - 1; i >= 0; i--) {
        while (j >= 0 && qry[i].first < a[j].first) {
            mx = std::max(mx, a[j].second);
            j--;
        }
        ans[qry[i].second] = mx;
        
    }

    for (int i = 0; i < Q; i++) {
        std::cout << ans[i] << "\n";
    }
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
