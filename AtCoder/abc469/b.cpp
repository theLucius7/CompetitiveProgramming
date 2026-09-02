#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'x') {
            int l = i - 1;
            if (l < 0 || S[l] == 'x') {
                int r = i + 1;
                if (r >= N || S[r] == 'x') {
                    cnt++;
                }
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
