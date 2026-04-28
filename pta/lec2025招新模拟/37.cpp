#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for (int i = 10; ; i++) {
        if ((i % 3 == 2) && (i % 5 == 3) && (i % 7 == 1)) {
            std::cout << i;
            return 0;
        }
    }

    return 0;
}