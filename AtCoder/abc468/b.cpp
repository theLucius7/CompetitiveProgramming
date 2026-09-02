#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int M, D;
    std::cin >> M >> D;

    std::string S;
    std::cin >> S;

    int cnt = 0;
    for (int i = 0; i < M; i++) {
        if (S[i] == '.') {
            bool ok = false;
            for (int j = i - 1; j >= std::max(0LL, i - D); j--) {
                if (S[j] == 'G') {
                    ok = true;
                }
            }
            for (int j = i + 1; j < std::min(M, i + D + 1); j++) {
                if (S[j] == 'G') {
                    ok = true;
                }
            }
            if (!ok) {
                cnt++;
            }
        }
    }
    std::cout << cnt << "\n";
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
