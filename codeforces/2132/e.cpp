#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m, q;
    std::cin >> n >> m >> q;

    std::vector<i64> a(n), b(m);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        std::cin >> b[i];
    }
    sort(a.begin(), a.end(), std::greater<i64>());
    sort(b.begin(), b.end(), std::greater<i64>());

    std::vector<i64> pa(n + 1, 0), pb(m + 1, 0);
    for (int i = 1; i <= n; i++) {
        pa[i] = pa[i - 1] + a[i - 1];
    }
    for (int i = 1; i <= m; i++) {
        pb[i] = pb[i - 1] + b[i - 1];
    }
    
    std::vector<std::array<int,3>> qs(q);
    int zmax = 0;
    for (int i = 0; i < q; ++i) {
        int x, y, z;
        std::cin >> x >> y >> z;
        qs[i] = {x, y, z};
        zmax = std::max(zmax, z);
    }
    zmax = std::min(zmax, n + m);

    std::vector<i64> S(zmax + 1, 0);
    std::vector<int> CA(zmax + 1, 0);
    int i = 0, j = 0;
    for (int k = 1; k <= zmax; ++k) {
        if (i < n && (j >= m || a[i] >= b[j])) {
            S[k] = S[k - 1] + a[i];
            CA[k] = CA[k - 1] + 1;
            ++i;
        } else {
            S[k] = S[k - 1] + b[j];
            CA[k] = CA[k - 1];
            ++j;
        }
    }

    auto solve = [&](int x, int y, int z) -> i64 {
        int L = std::max({0, z - y, z - m}), R = std::min({z, x, n});
        if (L > R) return -1;
        i64 s0 = S[z];
        int a0 = CA[z];
        int a = a0 < L ? L : (a0 > R ? R : a0);
        if (a == a0) return s0;
        int kb = z - a0;
        if (a > a0) {
            int d = a - a0;
            i64 dec = pb[kb] - pb[kb - d];
            i64 inc = pa[a0 + d] - pa[a0];
            return s0 - dec + inc;
        } else {
            int d = a0 - a;
            i64 dec = pa[a0] - pa[a0 - d];
            i64 inc = pb[kb + d] - pb[kb];
            return s0 - dec + inc;
        }
    };

    for (auto &qq : qs) {
        int x = qq[0], y = qq[1], z = qq[2];
        std::cout << solve(x, y, z) << '\n';
    }
}


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
