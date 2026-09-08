#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
using i64 = long long;

#define ing long long;

void solve() {
    int xn, yn, xr, yr;
    std::cin >> xn >> yn >> xr >> yr;

    int dx[] = {2, 2, -2, -2, 1, -1, 1, -1}, dy[] = {1, -1, 1, -1, 2, 2, -2, -2};
    int ndx[] = {1, 1, -1, -1, 0, 0, 0, 0}, ndy[] = {0, 0, 0, 0, 1, 1, -1, -1};
    for (int i = 0; i < 8; i++) {
        int nx = xn + dx[i], ny = yn + dy[i];
        int ux = xn + ndx[i], uy = yn + ndy[i];
        if (nx >= 1 && nx <= 9 && ny >= 1 && ny <= 10) {
            if (nx >= 1 && nx <= 9 && ny >= 1 && ny <= 10 && ux >= 1 && ux <= 9 && ny >= 1 && ny <= 10 && (ux != xr || uy != yr)) {
                // if (nx == xr && ny == yr) {
                //     std::cout << "NO\n";
                //     return;
                // }

                if (nx != xr && ny != yr) {
                    std::cout << "NO\n";
                    return;
                }
            }
        }
    }
    std::cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T -- ) {
        solve();
    }

    return 0;
}
