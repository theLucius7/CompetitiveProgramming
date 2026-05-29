#include <bits/stdc++.h>

using i64 = long long;

int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> x(N + 2);
    int ans = 0;
    while (Q--) {
        int A;
        std::cin >> A;

        ans -= x[A] != x[A - 1];
        ans -= x[A] != x[A + 1];

        x[A] ^= 1;

        ans += x[A] != x[A - 1];
        ans += x[A] != x[A + 1];

        std::cout << ans / 2 << "\n";
    }

    return 0;
}