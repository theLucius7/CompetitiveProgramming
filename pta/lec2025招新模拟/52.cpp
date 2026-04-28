#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    i64 c;
    std::cin >> n >> c;

    std::string A0 = "SWPUNB", A1 = "LECSOFTWARELEAGUE!!!";

    std::array<i64, 81> len;
    len[0] = A0.size();
    len[1] = A1.size();
    for (int i = 2; i <= n; i++) {
        len[i] = len[i - 2] + len[i - 1];
    }

    while (n > 1) {
        if (c <= len[n - 2]) {
            n -= 2;
        } else {
            c -= len[n - 2];
            n -= 1;
        }
    }

    if (n == 0) {
        std::cout << A0[c - 1] << "\n";
    } else {
        std::cout << A1[c - 1] << "\n";
    }

    return 0;
}
