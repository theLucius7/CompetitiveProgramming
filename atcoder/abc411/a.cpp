#include <bits/stdc++.h>

using i64 = long long;

int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string P;
    std::cin >> P;

    int L;
    std::cin >> L;

    std::cout << (P.size() >= L ? "Yes" : "No") << "\n";

    return 0;
}