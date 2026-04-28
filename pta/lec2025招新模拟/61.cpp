#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;

        double a, b, c;
        std::cin >> a >> b >> c;

        std::cout << s << " " << std::fixed << std::setprecision(2) << a + b - c << "\n";
    }


    return 0;
}