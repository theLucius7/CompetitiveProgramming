#include <bits/stdc++.h>

// using namespace std;
using i64 = long long;
using i128 = __int128;
// using real = long double;

// constexpr real eps = 1E-7L;

void solve() {
    i64 N, K;
    std::cin >> N >> K;

    if (K == 1) {
        std::cout << N << "\n";
        return;
    }

    for (i64 x = 2; ;x++) {
        i128 sum = 1;
        for (int i = 0; i < K; i++) {
            sum *= x;
            if (sum > N) {
                std::cout << x - 1 << "\n";
                return;
            }
        }
    }
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

