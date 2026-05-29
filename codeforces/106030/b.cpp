#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    long double ppmax;
    long double a, b, c, d, e, f;
    std::cin >> ppmax;
    // std::cout << ppmax << "\n";
    std::cin >> a >> b >> c >> d >> e >> f;
    // std::cout << a << " " << b << " " << c << " " << d << " " << e << " " << f << "\n";

    long double acc = (30 * a + 30 * b + 20 * c + 10 * d + 5 * e) / 30 / (a + b + c + d + e + f);
    std::cout << std::fixed << std::setprecision(2) << acc * 100 << "% ";

    long double x = ((long double)32 * a + 30 * b + 20 * c + 10 * d + 5 * e) / 32.0 / (a + b + c + d + e + f);
    // std::cout << x << "\n";
    // std::cout << ppmax << " ";
    long double pp = std::max((long double)0, x - 0.8) * 5 * ppmax + (long double)0.500000000001;
    // std::cout << pp << "\n";
    int np = pp;
    std::cout << np << "\n";
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