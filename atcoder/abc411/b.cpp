#include <bits/stdc++.h>

using i64 = long long;

int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<int> diff(N);
    for (int i = 1; i < N; i++) {
        std::cin >> diff[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int x = 0;
            for (int k = i + 1; k <= j; k++) {
                x += diff[k];
            }
            std::cout << x << " \n"[j == N - 1];
        }
    }

    return 0;
}