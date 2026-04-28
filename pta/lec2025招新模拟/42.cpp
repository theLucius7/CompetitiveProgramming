#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::getline(std::cin, s);

    char c;
    std::cin.get(c);

    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == c) {
            cnt++;
        }
    }
    std::cout << cnt << "\n";

    return 0;
}