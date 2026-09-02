#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N, M;
    std::cin >> N >> M;

    std::vector<int> C(M);
    for (int i = 0; i < M; i++) {
        std::cin >> C[i];
    }

    i64 res = 0;
    for (int i = 0; i < N; i++) {
        int A, B;
        std::cin >> A >> B;
        A--;
        res += std::min(B, C[A]);
        C[A] = std::max(0, C[A] - B);
    }

    std::cout << res << "\n";

    return 0;
}
