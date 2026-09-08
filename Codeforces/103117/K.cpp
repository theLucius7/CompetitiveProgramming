#include <bits/stdc++.h>

using i64 = long long;

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> p;
    for (int i = 1; i <= min(n, k); i ++ ) {
        for (int j = i; j <= n; j += k) {
            p.push_back(j);
        }
    }
    for (int i = 0; i < n; i ++ ) {
        cout << p[i] << " \n"[i == n - 1];
    }
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