#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    for (int i = 0; i < 2; i ++ ) {
        for (int j = 0; j < n; j ++ ) {
            int a;
            if ((i + j) & 1) {
                a = j + 1;
            } else {
                a = (j - 1 + n) % n + n + 1;
            }
            std::cout << a << " \n"[j == n - 1];
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t -- ) {
        solve();
    }
    
    return 0;
}
