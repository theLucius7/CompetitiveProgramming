#include <bits/stdc++.h>

#define int long long

using i128 = __int128;
using i64 = long long;
using u64 = unsigned long long;

constexpr int P = 998244353;
constexpr int L = 2E6;

int fac[L + 1], invfac[L + 1];
int sumbinom[L + 1][7];

int binom(int n, int m) {
    if (n < m || m < 0) {
        return 0;
    }
    return 1LL * fac[n] * invfac[m] % P * invfac[n - m] % P;
}

int power(int a, int b) {
    int res = 1;
    for (; b; b /= 2, a = 1LL * a * a % P) {
        if (b % 2) {
            res = 1LL * res * a % P;
        }
    }
    return res;
}

using i128 = __int128;
 
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
 
i128 toi128(const std::string &s) {
    i128 n = 0;
    for (auto c : s) {
        n = n * 10 + (c - '0');
    }
    return n;
}
 
i128 sqrti128(i128 n) {
    i128 lo = 0, hi = 1E16;
    while (lo < hi) {
        i128 x = (lo + hi + 1) / 2;
        if (x * x <= n) {
            lo = x;
        } else {
            hi = x - 1;
        }
    }
    return lo;
}

i128 gcd(i128 a, i128 b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

void solve() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    i128 s = 0, ss = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        s += A[i];
        ss += (i128)A[i] * A[i];
        s %= P;
        ss %= P;
    }

    if (K == 1) {
        std::cout << ss << "\n";
        return;
    }

    std::cout << (((i128)binom(N - 1, K - 1) * ss % P + (i128)binom(N - 2, K - 2) * (s * s - ss) % P) % P + P) % P<< "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    fac[0] = 1;
    for (int i = 1; i <= L; i++) {
        fac[i] = 1LL * fac[i - 1] * i % P;
    }
    invfac[L] = power(fac[L], P - 2);
    for (int i = L; i; i--) {
        invfac[i - 1] = 1LL * invfac[i] * i % P;
    }

    // sumbinom[0][0] = 1;
    // for (int i = 1; i <= L; i++) {
    //     for (int j = 0; j < 7; j++) {
    //         sumbinom[i][j] = (sumbinom[i - 1][j] + sumbinom[i - 1][(j + 6) % 7]) % P;
    //     }
    // }

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
