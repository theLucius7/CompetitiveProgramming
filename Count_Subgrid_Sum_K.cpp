#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int H, W, K;
    std::cin >> H >> W >> K;

    std::vector<std::string> s(H);
    for (int i = 0; i < H; i++) {
        std::cin >> s[i];
    }

    std::vector<int> sum(W);
    i64 ans = 0;
    std::vector<i64> cnt(H * W + 1);
    cnt[0]++;
    for (int r1 = 0; r1 < H; r1++) {
        for (int r2 = r1; r2 < H; r2++) {
            // std::unordered_map<int, i64> cnt;
            
            std::vector<i64> pre(W + 1);
            for (int j = 0; j < W; j++) {
                sum[j] += s[r2][j] - '0';

                pre[j + 1] = pre[j] + sum[j];
                if (pre[j + 1] - K >= 0) {
                    ans += cnt[pre[j + 1] - K];
                }

                cnt[pre[j + 1]]++;
            }

            for (int j = 0; j < W; j++) {
                cnt[pre[j + 1]]--;
            }
        }

        for (int r2 = r1; r2 < H; r2++) {
            for (int j = 0; j < W; j++) {
                sum[j] -= s[r2][j] - '0';
            }
        }
    }
    std::cout << ans << "\n";
    
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
