#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<int> P(N);
    for (int i = 0; i < N; i++) {
        std::cin >> P[i];
    }

    std::cout << std::max(0, *std::max_element(P.begin() + 1, P.end()) - P[0] + 1) << "\n";

    return 0;
}
