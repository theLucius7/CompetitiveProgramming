#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    auto p1 = s.find("LEC");
    auto p2 = s.find("LEC", p1 + 3);

    std::string t = s.substr(p1 + 3, p2 - p1 - 3);
    std::reverse(t.begin(), t.end());    
    std::cout << t << "\n";

    return 0;
}