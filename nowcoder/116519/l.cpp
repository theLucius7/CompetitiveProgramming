#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M, T;
    std::cin >> N >> M >> T;

    std::vector<int> R(N), C(M);
    for (int i = 0; i < T; ++i) {
        int x, y;
        std::cin >> x >> y;
        --x;
        --y;
        R[x]++;
        C[y]++;
    }

    auto calc = [&](int n, std::vector<int> v) -> int {
        int cnt = T / n;
        std::vector<int> a;
        a.reserve(n);
        int u = 0;
        for (int i = 0; i < n; i++) {
            u += v[i] - cnt;
            a.push_back(u);
        }

        std::sort(a.begin(), a.end());

        int m = a[n / 2];
        i64 ans = 0;
        for (int i = 0; i < a.size(); i++) {
            ans += std::abs(a[i] - m);
        }
        return ans;
    };

    if (T % N != 0 && T % M != 0) {
        std::cout << "impossible\n";
    } else if (T % N == 0 && T % M != 0) {
        std::cout << "row " << calc(N, R) << "\n";
    } else if (T % N != 0 && T % M == 0) {
        std::cout << "column " << calc(M, C) << "\n";
    } else {
        std::cout << "both " << calc(N, R) + calc(M, C) << "\n";
    }


    return 0;
}
