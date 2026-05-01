#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::string s, t;
    std::cin >> s >> t;

    // if (n == 1) {
    //     if (s.back() == '1' || t.back() == '1') {
    //         std::cout << 1 << "\n";
    //     } else {
    //         std::cout << 0 << "\n";
    //     }
    // } else {
    //     if ((s[n - 2] == '1' || t[n - 2] == '1') && (s[n - 1] == '1' || t[n - 1] == '1')) {
    //         std::cout << 1 << "\n";
    //     } else {
    //         std::cout << 0 << "\n";
    //     }
    // }

    for (int i = 0; i < n; i++) {
        if (s[i] != '1' && t[i] != '1') {
            std::cout << "0\n";
            return;
        }
    }
    std::cout << 1 << "\n";

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}