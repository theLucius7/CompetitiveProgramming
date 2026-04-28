#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int x;
    std::cin >> x;

    std::string s;
    std::cin >> s;

    i64 base = 1;
    i64 num = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        num += (s[i] - '0') * base;
        base *= 2;
    }

    std::string res;
    while (num > 0) {
        res = char('0' + num % x) + res;
        num /= x;
    }
    std::cout << res << "\n";


    return 0;
}
