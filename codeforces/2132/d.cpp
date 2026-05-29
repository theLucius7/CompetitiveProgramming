#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

i64 pw[19];

void solve() {  
    i64 k;
    std::cin >> k;
    
    i64 ans = 0;
    for (int d = 1; ; d++) {
        i64 len = d * (pw[d] - pw[d - 1]);
        if (len <= k) {
            i64 sum = (d - 1) * (pw[d] - pw[d - 1]) / 2 * 9 + (pw[d] - pw[d - 1]) * 5;
            k -= len;
            ans += sum;
        } else {
            int pre = 0;
            std::vector<int> dig;
            for (int i = 0; i < d; i++) {
                int c = k / d / pw[d - 1 - i];
                k -= c * d * pw[d - 1 - i];
                ans += pre * c * pw[d - 1 - i];
                ans += (i == 0 ? c * (c + 1) / 2 : c * (c - 1) / 2) * pw[d - 1 - i];
                ans += c * pw[d - 1 - i] * (d - 1 - i) / 2 * 9;
                dig.push_back(c + (i == 0));
                pre += c + (i == 0);
            }
            for (int i = 0; i < k; i++) {
                ans += dig[i];
            }
            break;
        }
    }
    
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    pw[0] = 1;
    for (int i = 1; i <= 18; i++) {
        pw[i] = pw[i - 1] * 10;
    }
    
    int T;
    std::cin >> T;
    
    while (T--) {
        solve();
    }
    
    return 0;
}
