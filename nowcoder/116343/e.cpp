#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 n, a, k;
    std::cin >> n >> a >> k;

    i64 cntA = (n + 1) / 2, cntB = n / 2;
    i64 max = (a + 1) / 2;
    int flag = -1;
    if (std::max(max, cntA) <= k && k <= a - cntB) {
        flag = 0;
    } else if (std::max(max, cntB) <= k && k <= a - cntA) {
        flag = 1;
    }
    if (flag == -1) {
        std::cout << -1 << "\n";
        return 0;
    }

    std::vector<i64> h(n, 1);
    i64 hA, hB;
    if (flag == 0) {
        hA = k;
        hB = a - k;
    } else {
        hB = k;
        hA = a - k;
    }

    
    if (hA - cntA > 0) {
        h[0] += hA - cntA;
    }
    if (hB - cntB > 0 && n > 1) {
        h[1] += hB - cntB;
    }
    for (int i = 0; i < n; i++) {
        std::cout << h[i] << " \n"[i == n - 1];
    }

    return 0;
}
