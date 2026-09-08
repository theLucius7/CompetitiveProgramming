#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1E9 + 1;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<i64> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
    }

    auto check = [&](i64 x) {
        for (i64 i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                return true;
            }
        }
        return false;
    };

    for (int i = 0; i <= n; i++) {
        // std::cout << pre[i] << " \n"[i == n];
    }


    int min = inf;
    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
            if (check(pre[r + 1] - pre[l])) {
                // std::cout << l << " " << r << "?";
                min = std::min(min, r - l);
            }
        }
    }
    std::cout << (min == inf ? -1 : min) << "\n";

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