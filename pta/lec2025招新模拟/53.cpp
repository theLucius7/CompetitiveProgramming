#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<std::array<int, 2>> ans;
    for (int i = 1; i <= std::sqrt(n); i++) {
        if (n % i == 0) {
            ans.push_back({i, n / i});
        }
    }

    std::cout << ans.size() << "\n";
    for (auto [x, y] : ans) {
        std::cout << x << " " << y << "\n";
    }

    return 0;
}
