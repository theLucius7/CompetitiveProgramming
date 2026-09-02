#include <bits/stdc++.h>

using i64 = long long;

using real = long double;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int a, b, c, d;
    i64 s = 0;
    while (std::cin >> a >> b >> c >> d && (a || b || c || d)) {
        if (d == 1) {
            s += 1LL * a * 3600 + b * 60 + c;
        }
    }
    
    real ans = 1.L * s / 3600;
    std::cout << std::fixed << std::setprecision(2) << ans << "\n";
    if (ans <= 24.0) {
        std::cout << "Yes!\n";
    } else {
        std::cout << "No!\n";
    }
    
    return 0;
}
