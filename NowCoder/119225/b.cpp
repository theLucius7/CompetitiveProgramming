#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

constexpr int mod = 1000000007;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<i64> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i] >> b[i];
    }

    i64 x = a[0], y = b[0];
    for (int i = 1; i < n; i++) {
        i64 nx = (x * a[i] - y * b[i]) % mod;
        nx = (nx + mod) % mod;
        i64 ny = (y * a[i] + x * b[i]) % mod;
        ny = (ny + mod) % mod;

        x = nx, y = ny;
    }

    std::cout << x << " " << y << "\n";
    
    return 0;
}
