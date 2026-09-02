#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int N;
    std::cin >> N;

    std::vector<int> a(N);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }
    a.push_back(0);
    std::sort(a.begin(), a.end());

    constexpr int inf = 1E18;

    int cur = std::distance(a.begin(), std::lower_bound(a.begin(), a.end(), 0));
    int l = cur, r = cur;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        int ld = (l - 1 >= 0 ? a[cur] - a[l - 1] : inf);
        int rd = (r + 1 <= N ? a[r + 1] - a[cur] : inf);
        if (ld <= rd) {
            sum += ld;
            cur = --l;
        } else {
            sum += rd;
            cur = ++r;
        }
    }
    std::cout << sum << "\n";

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
