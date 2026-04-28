#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    std::cin >> N;

    std::string s = std::to_string(N);
    for (int i = 3; i < s.size(); i++) {
        s[i] = '0';
    }
    std::cout << s << "\n";

    return 0;
}
