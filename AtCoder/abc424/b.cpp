#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M, K;
    std::cin >> N >> M >> K;

    std::vector<int> cnt(N);
    std::vector<int> ans;
    for (int i = 0; i < K; i++) {
        int A, B;
        std::cin >> A >> B;
        A--;
        cnt[A]++;

        if (cnt[A] == M) {
            ans.push_back(A);
        }
    }

    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i] + 1 << " \n"[i == ans.size() - 1];
    }

    return 0;
}