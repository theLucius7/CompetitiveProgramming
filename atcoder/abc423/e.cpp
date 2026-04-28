#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<i64> s0(N + 1), s1(N + 1), s2(N + 1);
    for (int i = 0; i < N; i++) {
        s0[i + 1] = s0[i] + A[i];
        s1[i + 1] = s1[i] + 1LL * A[i] * (i + 1);
        s2[i + 1] = s2[i] + 1LL * A[i] * (i + 1) * (i + 1);
    }

    while (Q--) {
        int L, R;
        std::cin >> L >> R;
        i64 A = -1, B = L + R, C = R - L -  1LL * L * R + 1;
        L--, R--;
        std::cout << A * (s2[R + 1] - s2[L]) + B * (s1[R + 1] - s1[L]) + C * (s0[R + 1] - s0[L]) << "\n";
    }


    return 0;
}
