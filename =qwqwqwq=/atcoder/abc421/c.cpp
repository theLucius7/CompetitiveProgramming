#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::string S;
    std::cin >> N >> S;

    std::vector<int> A, B;
    for (int i = 0; i < 2 * N; i++) {
        if (i % 2 == 0 && S[i] == 'B') {
            A.push_back(i);
        }
        if (i % 2 == 1 && S[i] == 'A') {
            B.push_back(i);
        }
    }


    int cnt = 0;
    for (int i = 0; i < A.size(); i++) {
        cnt += std::abs(A[i] - B[i]);
    }

    int ans = INT_MAX;
    ans = std::min(cnt, ans);

    A.clear();
    B.clear();
    for (int i = 0; i < 2 * N; i++) {
        if (i % 2 == 0 && S[i] == 'A') {
            A.push_back(i);
        }
        if (i % 2 == 1 && S[i] == 'B') {
            B.push_back(i);
        }
    }
    cnt = 0;
    for (int i = 0; i < A.size(); i++) {
        cnt += std::abs(A[i] - B[i]);
    }

    ans = std::min(cnt, ans);
    std::cout << ans << "\n";

    return 0;
}
