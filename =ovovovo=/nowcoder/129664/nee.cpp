#include <bits/stdc++.h>
using i64 = long long;
void solve() {
    int n;
    std::cin >> n;
    std::vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) std::cin >> p[i];
    if (p[1] != 1) {
        std::cout << -1 << "\n";
        return;
    }
    std::vector<int> s(n + 1);
    s[1] = 1;
    bool ok = true;
    for (int j = 2; j <= n; j++) {
        if (p[j] == j) {
            s[j] = 1;
        } else if (p[j] == p[j - 1]) {
            s[j] = s[p[j]] + 1;
        } else {
            ok = false;
            break;
        }
    }
    if (!ok) {
        std::cout << -1 << "\n";
        return;
    }
    for (int i = 1; i <= n; i++) {
        std::cout << s[i] << " \n"[i == n];
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
