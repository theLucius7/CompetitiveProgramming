#include <bits/stdc++.h>

using i64 = long long;
using namespace std;

#define int long long

void solve() {
    int n, k;
    std::cin >> n >> k;

    // if (n == 1) {
    //     if (k == 1) {
    //         cout << "1\n";
    //     } else {
    //         cout << "2\n";
    //     }
    //     return;
    // }

    // if (k == 0) {
    //     if (n % 2) {
    //         for (int i = 0; i < n / 2; i++) {
    //             std::cout << 1;
    //         }
    //         for (int i = 0; i < n / 2; i ++ ) {
    //             std::cout << 3;
    //         }
    //         cout << 2;
    //     } else {
    //         for (int i = 0; i < n / 2; i++) {
    //             std::cout << 1;
    //         }
    //         for (int i = 0; i < n / 2; i ++ ) {
    //             std::cout << 3;
    //         }
    //     }
    // } else if (k == n) {
    //     for (int i = 0; i < n; i ++ ) {
    //         cout << 1;
    //     }
    // } else if (k * 2 == n) {
    //     for (int i = 0; i < n / 2; i ++ ) {
    //         cout << 2;
    //     }
    //     for (int i = 0; i < n / 2; i ++ ) {
    //         cout << 3;
    //     }
    // } else if (k * 2 + 1 == n) {
    //     for (int i = 0; i < k + 1; i++) {
    //         std::cout << 2;
    //     }
    //     for (int i = k + 1; i < n; i++) {
    //         std::cout << 3;
    //     }
    // } else if (k * 2 - 1 == n) {
    //     for (int i = 0; i < k - 1; i++) {
    //         std::cout << 2;
    //     }
    //     for (int i = k - 1; i < n; i++) {
    //         std::cout << 3;
    //     }
    // }else {
    //     cout << -1;
    // }

    for (int i = 0; i < n - k; i ++ ) {
        cout << 2;
    }
    for (int i = n - k; i < n; i ++ ) {
        cout << 3;
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);


    int t = 1;
    // std::cin >> t;

    while (t--) {
        solve();
    }

}