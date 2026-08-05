#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;
    
    int sum = 0;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        sum ^= a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
        sum ^= b[i];
    }

    a.push_back(0);
    b.push_back(0);

    for (int i = 0; i < a.size(); i++) {
        a[i] ^= sum;
    }

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    std::cout << (a == b ? "YES" : "NO") << "\n";

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
