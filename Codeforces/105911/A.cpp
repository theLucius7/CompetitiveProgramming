#include <bits/stdc++.h>

using i64 = long long;
using namespace std;

#define int long long

void solve() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    std::cout << (a + b + c) * d << "\n";
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