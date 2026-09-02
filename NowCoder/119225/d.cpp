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
    
    i64 n;
    std::cin >> n;

    i64 base = 1;
    for (int i = 1; i < n; i++) {
        base = (base * i) % mod;
    }

    i64 ans = ((n / 10) * 20 * base) % mod;
    for (int i = 1; i <= n % 10; i++) {
        ans = (ans + (base * (i % 5))) % mod;
    }
    std::cout << ans << "\n";

    return 0;
}
