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

    std::vector<int> p(3);
    for (int i = 0; i < n; i++) {
        i64 x;
        std::cin >> x;
        while (x % 2 == 0) {
            p[0]++;
            x /= 2;
        }
        while (x % 3 == 0) {
            p[1]++;
            x /= 3;
        }
        while (x % 5 == 0) {
            p[2]++;
            x /= 5;
        }
    }

    std::cout << *std::min_element(p.begin(), p.end()) << "\n";

    return 0;
}
