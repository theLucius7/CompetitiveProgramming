#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<i64> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    if (a[n - 1] != b[n - 1]) {
        std::cout << "NO\n";
        return;
    }

    for (int i = n - 2; i >= 0; i--) {
        if ((b[i] != a[i]) && b[i] != (a[i] ^ b[i + 1]) && (b[i] != (a[i] ^ a[i + 1]))) {
            std::cout << "NO\n";
            return;
        }
    }
    std::cout << "YES\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int T; 
    std::cin >> T;

    while (T--) {
        solve();    
    }

    return 0;
}