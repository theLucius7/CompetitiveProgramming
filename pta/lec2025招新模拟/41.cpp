#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int cur = 1, max = 0;
    for (int i = 1; i <= n; i++) {
        if (i < n && std::abs(a[i] - a[i - 1]) <= 1) {
            cur++;
        } else {
            max = std::max(max, cur);
            cur = 1;
        }
    }
    std::cout << max << "\n";

    return 0;
}