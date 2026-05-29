#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, Q;
    std::cin >> N >> Q;

    std::vector<i64> A(N), B(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    i64 minsum = 0;
    for (int i = 0; i < N; i++) {
        minsum += std::min(A[i], B[i]);
    }

    while (Q--) {
        char C;
        i64 X, V;
        std::cin >> C >> X >> V;
        X--;

        minsum -= std::min(A[X], B[X]);
        
        if (C == 'A') {
            A[X] = V;
        } else {
            B[X] = V;
        }

        minsum += std::min(A[X], B[X]);
        std::cout << minsum << "\n";

    }

    return 0;
}
