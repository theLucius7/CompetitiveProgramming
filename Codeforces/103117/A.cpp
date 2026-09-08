#include <bits/stdc++.h>

using i64 = long long;

using namespace std;

void solve() {
    int k;
    std::cin >> k;

    int cnt = 0;

    for (int i = 1; i <= 6; i++) {
        for (int j = i; j <= 6; j++) {
            cnt += (i + j == k);
        }
    }
    std::cout << cnt << "\n";
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