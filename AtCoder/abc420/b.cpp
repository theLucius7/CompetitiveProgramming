#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    std::vector<std::string> S(N);
    for (int i = 0; i < N; i++) {
        std::cin >> S[i];
    }

    std::vector<int> v(N);
    for (int j = 0; j < M; j++) {
        int cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < N; i++) {
            if (S[i][j] == '1') {
            	cnt1++;
            } else {
            	cnt0++;
            }
        }

        char f = (cnt1 < cnt0) ? '1' : '0';
        for (int i = 0; i < N; i++) {
            if (S[i][j] == f) {
            	v[i]++;
            }
        }
    }

    int x = *std::max_element(v.begin(), v.end());
    for (int i = 0; i < N; i++) {
        if (v[i] == x) {
            std::cout << (i + 1) << " ";
        }
    }
    std::cout << "\n";

    return 0;
}
