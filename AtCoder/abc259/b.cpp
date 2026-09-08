#include <bits/stdc++.h>

using i64 = long long;

const double Pi = std::acos(-1);

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int a, b, d;
    std::cin >> a >> b >> d;
    
    double ang = d * Pi / 180;
    
    double x = a * std::cos(ang) - b * std::sin(ang);
    double y = a * std::sin(ang) + b * std::cos(ang);
    
    std::cout << std::fixed << std::setprecision(10) << x << " " << y << "\n";
    
    return 0;
}