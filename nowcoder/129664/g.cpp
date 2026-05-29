#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, a;
    std::cin >> n >> a;
    
    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
    	std::cin >> v[i];
    }
    
    std::vector<int> t(n);
    for (int i = 0; i < n; i++) {
        t[i] = 3 - v[(i - 1 + n) % n] - v[i] - v[(i + 1) % n];
    }
    
    std::sort(t.begin(), t.end());
    
    i64 sum = 3 * n;
    for (int i = 0; i < a; i++) {
        sum -= t[i];
    }
    
    std::cout << sum << "\n";
    
    return 0;
}
