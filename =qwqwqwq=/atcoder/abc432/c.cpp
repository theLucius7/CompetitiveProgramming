#include <bits/stdc++.h>

using i64 = long long;

using i128 = __int128;

constexpr i128 inf = 4E18 + 1;

std::ostream &operator<<(std::ostream &os, i128 n) {
    if (n == 0) {
        return os << 0;
    }
    std::string s;
    while (n > 0) {
        s += char('0' + n % 10);
        n /= 10;
    }
    std::reverse(s.begin(), s.end());
    return os << s;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    i64 X, Y;
    std::cin >> X >> Y;

    std::vector<i64> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    i64 D = Y - X;
    i64 g = std::gcd(X, D);
    i64 Dg = D / g, Xg = X / g;

    i128 min = -inf, max = inf, sum = 0;
    for (int i = 0; i < N; i++) {
        i64 diffA = A[0] - A[i];
        if (diffA % Dg != 0) {
            std::cout << -1 << "\n";
            return 0;
        }
        i128 diff = (i128)Xg * diffA / Dg;

        sum += diff;

        min = std::max(min, -diff);
        max = std::min(max, (i128)A[i] - diff);
    }

    if (min > max) {
        std::cout << -1 << "\n";
        return 0;
    }

    std::cout << sum + (i128)N * max << "\n";

    return 0;
}
