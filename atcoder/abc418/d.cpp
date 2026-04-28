#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::string T;

    std::cin >> N >> T;

    i64 cnt[2] = {1, 0};
    int x = 0;

    for (char c : T) {
        if (c == '0') {
            x ^= 1;
        }
        cnt[x]++;
    }

    std::cout << (cnt[0] * (cnt[0] - 1) / 2) + (cnt[1] * (cnt[1] - 1) / 2) << '\n';

    return 0;
}
