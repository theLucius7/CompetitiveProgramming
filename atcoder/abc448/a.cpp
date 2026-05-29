#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N, X;
    std::cin >> N >> X;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        if (A[i] < X) {
            std::cout << 1 << "\n";
            X = A[i];
        } else {
            std::cout << 0 << "\n";
        }
    }
    
    return 0;
}
