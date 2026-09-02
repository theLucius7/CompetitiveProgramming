#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int N, M, K;
    std::cin >> N >> M >> K;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> B(N);
    int l = 0;
    int sum = 0;
    for (int r = 0; r < N; r++) {
        if (r - l + 1 > M) {
            sum -= B[l];
            l++;
        }
        if (sum + A[r] <= K) {
            sum += A[r];
            B[r] = A[r];
            // r++;
        }
    }

    for (int i = 0; i < N; i++) {
        if (B[i]) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
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
