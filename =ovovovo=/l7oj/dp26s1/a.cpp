#include <bits/stdc++.h>

// using namespace std;
using i64 = long long;
using real = long double;

constexpr real eps = 1E-7L;

void solve() {
    int N, K;
    std::cin >> N >> K;

    auto check = [&](real t) {
        real r = 1;
        for (int i = 0; i < K; i++) {
            r *= t;
        }
        return r >= N;
    };

    real lo = 0;
    real hi = 1E12;
    while (hi - lo > std::max(1.L, lo) * eps) {
        real x = (lo + hi) / 2;
        if (check(x)) {
            hi = x;
        } else {
            lo = x;
        }
    }
    std::cout << lo << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

