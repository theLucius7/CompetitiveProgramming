#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int x = n - 1;
    for (int i = 0; i < std::min(n, k); i++) {
        if (a[x] > n) {
            std::cout << "NO\n";
            return;
        }

        x = (x - a[x] + n) % n;
    }
    std::cout << "YES\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}