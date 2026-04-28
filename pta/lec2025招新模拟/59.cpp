#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, K;
    std::cin >> N >> K;
    std::vector<std::string> v(N);
    for (int i = 0; i < N; i++) {
        std::cin >> v[i];
    }

    for (int i = 0; i < K; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                std::swap(v[j], v[j + 1]);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        std::cout << v[i] << "\n";
    }

    return 0;
}
