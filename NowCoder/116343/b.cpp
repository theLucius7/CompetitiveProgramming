#include <bits/stdc++.h>

using i64 = long long;

int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(2 * n), id(n + 1, -1);
    int ans = 0;
    for (int i = 0; i < 2 * n; i++) {
        std::cin >> a[i];
        if (id[a[i]] != -1) {
            ans = std::max(ans, i - id[a[i]] + 1);
        } else {
            id[a[i]] = i;
        }
    }
    std::cout << ans << "\n";

    return 0;
}