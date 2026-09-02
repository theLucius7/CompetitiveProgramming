#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::pair<int, int>> p(M);

    for (int i = 0; i < M; i++) {
        std::cin >> p[i].first >> p[i].second;
        p[i].first--;
        p[i].second--;
    }

    int cnt = 0;
    std::vector<int> cmf(N);
    for (int i = 1; i < M; i++) {
        if (p[i].first != p[0].first && p[i].second != p[0].first) {
            cnt++;
            cmf[p[i].first]++;
            cmf[p[i].second]++;
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (i != p[0].first && cmf[i] == cnt) {
            ans++;
        }
    }
    cnt = 0;
    std::vector<int> cms(N);
    for (int i = 01; i < M; i++) {
        if (p[i].first != p[0].second && p[i].second != p[0].second) {
            cnt++;
            cms[p[i].first]++;
            cms[p[i].second]++;
        }
    }

    for (int i = 0; i < N; i++) {
        if (i != p[0].second && i != p[0].first && cms[i] == cnt) {
            // std::cout << i << "?\n";
            ans++;
        }
    }
    std::cout << ans << "\n";
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
