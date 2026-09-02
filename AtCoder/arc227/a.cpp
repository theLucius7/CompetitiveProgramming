#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int N;
    std::cin >> N;

    std::vector<std::string> S(3);
    for (int i = 0; i < 3; i++) {
        std::cin >> S[i];
    }

    std::vector<std::array<int, 3>> ps(N);
    for (int i = 0; i < 3; i++) {
        int cnt = 0;
        for (int j = 0; j < 2 * N; j++) {
            if (S[i][j] == '0') {
                ps[cnt][i] = j;
                cnt++;
            }
        }
    }

    int sum = 0;
    std::string ans(2 * N, '1');
    for (int i = 0; i < N; i++) {
        std::sort(ps[i].begin(), ps[i].end());
        ans[ps[i][1]] = '0';
        sum += ps[i][2] - ps[i][0];
    }
    std::cout << sum << "\n";
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
