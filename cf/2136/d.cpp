#include <bits/stdc++.h>

using i64 = long long;

void solve () {
    int n;
    std::cin >> n;

    std::vector<std::pair<i64, i64>> p(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i].first >> p[i].second;
    }

    i64 maxSum = LLONG_MIN, maxDiff = LLONG_MIN;
    for (auto [x, y] : p) {
        maxSum = std::max(maxSum, x + y);
        maxDiff = std::max(maxDiff, x - y);
    }

    i64 k = 1'000'000'000LL, fake, res1, res2;
    std::cout << "? " << "R" << " " << k << "\n";
    std::cout.flush();
    std::cin >> fake;

    std::cout << "? " << "R" << " " << k << "\n";
    std::cout.flush();
    std::cin >> fake;

    std::cout << "? " << "U" << " " << k << "\n";
    std::cout.flush();
    std::cin >> fake;

    std::cout << "? " << "U" << " " << k << "\n";
    std::cout.flush();
    std::cin >> res1;

    std::cout << "? " << "D" << " " << k << "\n";
    std::cout.flush();
    std::cin >> fake;

    std::cout << "? " << "D" << " " << k << "\n";
    std::cout.flush();
    std::cin >> fake;

    std::cout << "? " << "D" << " " << k << "\n";
    std::cout.flush();
    std::cin >> fake;

    std::cout << "? " << "D" << " " << k << "\n";
    std::cout.flush();
    std::cin >> res2;

    i64 sum = res1 - 4 * k + maxSum;
    i64 diff = res2 - 4 * k + maxDiff;

    std::cout << "! " << (sum + diff) / 2 << " " << (sum - diff) / 2 << "\n";
    std::cout.flush();
}

int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}