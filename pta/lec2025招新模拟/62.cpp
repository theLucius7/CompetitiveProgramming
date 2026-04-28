#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<std::string> s(n), t(n);
    int max = -1, ans = -1;
    for (int i = 0; i < n; i++) {
        std::cin >> t[i] >> s[i];
        int a, b, c;
        std::cin >> a >> b >> c;
        
        i64 sum = a + b + c;
        if (sum > max) {
            max = sum;
            ans = i;
        }
    }

    std::cout << s[ans] << " " << t[ans] << " " << max << "\n";


    return 0;
}