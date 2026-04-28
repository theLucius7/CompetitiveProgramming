#include<bits/stdc++.h>

using i64 = long long;
 
void solve() {
    int a, b;
    std::cin >> a >> b;

    i64 x = 1LL * std::max(a, b) * std::max(a, b) - 1LL * std::min(a, b) * std::min(a, b);
    if (x == 3) {
        std::cout << 1 << "\n";
        return;
    }
    std::cout << (3 * (x - 4) + 6) / 4 << "\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }



    return 0;
}