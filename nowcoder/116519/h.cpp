#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    std::vector<int> C(N);
    for (int i = 0; i < N; i++) {
        std::cin >> C[i];
    }

    std::vector<i64> pref0(N + 1), pref1(N + 1);
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            pref0[i + 1] = pref0[i] + (S[i] == '0' ? 0 : C[i]);
            pref1[i + 1] = pref1[i] + (S[i] == '1' ? 0 : C[i]);
        } else {
            pref0[i + 1] = pref0[i] + (S[i] == '1' ? 0 : C[i]);
            pref1[i + 1] = pref1[i] + (S[i] == '0' ? 0 : C[i]);
        }
    }

    i64 ans = LLONG_MAX;
    for (int i = 0; i < N - 1; i++) {
        ans = std::min({ans, pref0[i + 1] + pref1[N] - pref1[i + 1], pref1[i + 1] + pref0[N] - pref0[i + 1]});
    }
    std::cout << ans << "\n";

    return 0;
}
