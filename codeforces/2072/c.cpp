#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    int n, x;
    std::cin >> n >> x;

    bool ok = true;
    int cur = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            if (ok && ((cur | sum) == x)) {
                std::cout << cur << "\n";
            } else {
                std::cout << x << "\n";    
            }
        } else {
            if (ok) {
                if ((cur | x) == x) {
                    sum |= cur;
                    std::cout << cur << " ";
                    cur++;
                } else {
                    ok = false;
                    std::cout << x << " ";
                }
            } else {
                std::cout << x << " ";
            }
        }
    }
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
