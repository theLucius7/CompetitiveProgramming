#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

i64 mul(i64 a, i64 b, i64 p) {
    i64 c = a * b - i64(1.0L * a * b / p) * p;
    c %= p;
    if (c < 0) {
        c += p;
    }
    return c;
}

i64 power(i64 a, i64 b, i64 p) {
    i64 res = 1;
    for (; b; b /= 2, a = mul(a, a, p)) {
        if (b % 2) {
            res = mul(res, a, p);
        }
    }
    return res;
}

void solve() {
    int N;
    std::cin >> N;


    std::vector<int> d(2 * N + 10);
    std::vector<int> S(N), T(N);
    std::vector<int> vT(N);
    for (int i = 0; i < N; i++) {
        std::cin >> S[i] >> T[i];
        vT[i] = T[i];
        d[S[i]]++;
        d[T[i]]--;
    }

    int u = 0;
    for (int i = 1; i <= 2 * N; i++) {
        u += d[i];
        if (u >= 3) {
            std::cout << 0 << "\n";
            return;
        }
    }

    std::sort(vT.begin(), vT.end());

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        cnt += std::distance(vT.begin(), std::lower_bound(vT.begin(), vT.end(), S[i]));
        // std::cout << std::distance(vT.begin(), std::lower_bound(vT.begin(), vT.end(), S[i])) << " \n"[i == N - 1];
    }

    constexpr int P = 998244353;
    std::cout << power(2, N - (N * (N - 1) / 2 - cnt), P) << "\n";
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
