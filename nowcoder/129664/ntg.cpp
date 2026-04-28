#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, a;
    std::cin >> n >> a;
    std::vector<int> b(n);
    for (auto &x : b) std::cin >> x;
    
    std::vector<int> v(n);
    for (int j = 0; j < n; j++) {
        v[j] = b[(j-1+n)%n] + b[j] + b[(j+1)%n];
    }
    
    i64 base = 0;
    std::vector<int> delta(n);
    for (int j = 0; j < n; j++) {
        base += (3 - v[j]);
        delta[j] = 2*v[j] - 3;
    }
    
    std::sort(delta.begin(), delta.end(), std::greater<int>());
    
    i64 ans = base;
    for (int i = 0; i < a; i++) ans += delta[i];
    
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
