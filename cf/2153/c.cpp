#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::sort(a.begin(), a.end());

    std::vector<i64> b;
    b.push_back(0);
    i64 sum = 0;
    int cnt = 0;
    for (int l = 0, r = 0; l < n; l = r) {
        while (r < n && a[r] == a[l]) {
            r++;
        }

        sum += (i64)(r - l) / 2 * 2 * a[l];
        cnt += (r - l) / 2 * 2;
        if ((r - l) % 2) {
            b.push_back(a[l]);
        }
    }

    i64 max = 0;
    for (int i = 1; i < b.size(); i++) {
        if (b[i] < sum + b[i - 1]) {
            max = std::max(max, b[i] + b[i - 1]);
        }
    }

    // std::cout << cnt << " " << max << " " << sum << "\n";

    if (cnt > 2 || (cnt == 2 && max)) {
        std::cout << max + sum << "\n";
    } else {
        std::cout << 0 << "\n";
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
