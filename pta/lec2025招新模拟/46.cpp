#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 A, B;
    std::cin >> A >> B;

    auto ok = [&](int K) -> bool {
        std::string s = std::to_string(A);
        std::reverse(s.begin(), s.end());
        i64 res = 0, pow = 1;
        for (int i = 0; i < s.size(); i++) {
            res += (s[i] - '0') * pow;
            pow *= K;
        }
        return res == B;
    };

    for (int i = 2; i <= 10; i++) {
        if (ok(i)) {
            std::cout << i << "\n";
            return 0;
        }
    }


    return 0;
}