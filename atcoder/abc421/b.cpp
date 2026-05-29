#include <bits/stdc++.h>

using i64 = long long;

int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto f = [](std::string s) -> i64 {
        std::reverse(s.begin(), s.end());
        return stoll(s);
    };

    std::vector<i64> a(10);
    std::cin >> a[0] >> a[1];

    for (int i = 2; i < 10; i++) {
        a[i] = f(std::to_string(a[i - 1] + a[i - 2]));
    }
    std::cout << a[9] << "\n";

    return 0;
}