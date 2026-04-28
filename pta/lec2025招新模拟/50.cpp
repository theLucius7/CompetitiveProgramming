#include <bits/stdc++.h>

using i64 = long long;
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


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<std::vector<i128>> a(n, std::vector<i128>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            long long x; std::cin >> x;
            a[i][j] = (i128)x;
        }
    }

    int sign = 1;
    i128 prev = 1;

    for (int k = 0; k < n - 1; k++) {
        int pivot = k;
        while (pivot < n && a[pivot][k] == 0) ++pivot;
        if (pivot == n) {
            std::cout << 0 << "\n";
            return 0;
        }
        if (pivot != k) {
            std::swap(a[pivot], a[k]);
            sign = -sign;
        }

        for (int i = k + 1; i < n; ++i) {
            for (int j = k + 1; j < n; ++j) {
                i128 num = a[i][j] * a[k][k] - a[i][k] * a[k][j];
                if (prev != 0) {
                    num /= prev;
                }
                a[i][j] = num;
            }
        }
        for (int i = k + 1; i < n; ++i) {
            a[i][k] = 0;
        }

        prev = a[k][k];
    }

    i128 det = a[n - 1][n - 1] * sign;
    std::cout << det << '\n';

    return 0;
}
