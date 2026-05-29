#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    std::vector<int> d(N);
    i64 ans = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        d[i] = 1;
        ans += A[i];
    }

    std::priority_queue<std::pair<i64, int>, std::vector<std::pair<i64, int>>, std::greater<>> q;
    for (int i = 0; i < N; i++) {
        q.emplace((2LL * d[i] + 1) * A[i], i);
    }

    for (int t = 0; t < N - 2; t++) {
        auto [x, i] = q.top();
        q.pop();
        ans += x;
        d[i]++;
        q.emplace((2LL * d[i] + 1) * A[i], i);
    }

    std::cout << ans << "\n";


    return 0;
}
