#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> A(n), B(n);
    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> B[i];
    }

    if (A == B) {
        std::cout << 0 << "\n";
        return;
    }

    if (std::count(A.begin(), A.end(), 0) == n) {
        std::cout << -1 << "\n";
        return;
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] == 1 && B[i] == 0) {
            cnt++;
        }
    }

    if (cnt == 0) {
        bool ok = false;
        for (int i = 0; i < n; i++) {
            if (A[i] == 0 && B[i] == 0) {
                ok = true;
                break;
            }
        }

        std::cout << (ok ? 2 : -1) << "\n";
    } else if (cnt & 1) {
        std::cout << 1 << "\n";
    } else {
        std::cout << 2 << "\n";
    }
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
