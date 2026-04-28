#include <bits/stdc++.h>

using i64 = long long;
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    cout << (m - (n + 1) / 2) * 2 + 1 << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t -- ) {
        solve();
    }

    return 0;
}