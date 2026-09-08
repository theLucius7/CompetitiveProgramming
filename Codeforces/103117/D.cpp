#include <bits/stdc++.h>

#define int long long

using i64 = long long;

using namespace std;



void solve() {
    std::vector<int> a(3), b(3);
    for (int i = 0; i < 3; i++) {
        std::cin >> a[i];
    }
    for (int j = 0; j < 3; j++) {
        std::cin >> b[j];
    }

    int ans = 0;
    for (int i = 0; i < 3; i++) {
        if (i == 0) {
            int x = std::min(b[i], a[2]);
            ans += x;
            b[i] -= x;
            a[2] -= x;

            if (b[i]) {
                int y = std::min(b[i], a[0]);
                b[i] -= y;
                a[0] -= y;

                if (b[i]) {
                    int z = std::min(b[i], a[1]);
                    ans -= z;
                    b[i] -= z;
                    a[1] -= z;
                }
            }
        } else if (i == 1) {
            int x = std::min(b[i], a[0]);
            ans += x;
            b[i] -= x;
            a[0] -= x;

            if (b[i]) {
                int y = std::min(b[i], a[1]);
                b[i] -= y;
                a[1] -= y;

                if (b[i]) {
                    int z = std::min(b[i], a[2]);
                    ans -= z;
                    b[i] -= z;
                    a[2] -= z;
                }
            }
        } else if (i == 2) {
            int x = std::min(b[i], a[1]);
            ans += x;
            b[i] -= x;
            a[1] -= x;

            if (b[i]) {
                int y = std::min(b[i], a[2]);
                b[i] -= y;
                a[2] -= y;

                if (b[i]) {
                    int z = std::min(b[i], a[0]);
                    ans -= z;
                    b[i] -= z;
                    a[0] -= z;
                }
            }
        }
    }

    std::cout << ans << "\n";
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