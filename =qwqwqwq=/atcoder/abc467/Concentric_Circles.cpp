#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int Px, Py, Qx, Qy, Rx, Ry, Sx, Sy;
    std::cin >> Px >> Py >> Qx >> Qy >> Rx >> Ry >> Sx >> Sy;

    // std::cout << (Py - Qy) * (Qx + Px - Rx - Sx) << " " <<  (Px - Qx) * (Qy + Py - Ry - Sy) << "\n";

    std::cout << (((Py - Qy) * (Rx - Sx) == (Ry - Sy) * (Px - Qx)) && ((Px - Qx) * (Qx + Px - Rx - Sx) != -1 * (Py - Qy) *  (Qy + Py - Ry - Sy)) ? "No" : "Yes") << "\n";
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
