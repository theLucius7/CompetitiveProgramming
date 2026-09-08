#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::string s;
    std::cin >> s;
    
    std::map<int, int> f;
    
    int res = 0;
    for (int i = 0; i < n; i++) {
        int w;
        std::cin >> w;
        res += (s[i] == '1');
        f[w] += (s[i] == '0' ? 1 : -1);
    }
    
    int ans = res;
    for (auto [_, x] : f) {
        res += x;
        ans = std::max(ans, res);
    }
    
    std::cout << ans << "\n";
    
    return 0;
}
