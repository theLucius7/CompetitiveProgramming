#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    std::cin >> N;

    std::vector<std::string> S(N);
    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> S[i] >> A[i];
    }

    int s = std::min_element(A.begin(), A.end()) - A.begin();
    for (int i = 0; i < N; i++) {
        std::cout << S[(s + i) % N] << "\n";
    }

    return 0;
}
