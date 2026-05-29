#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    std::cin >> N;

    std::vector<int> H(N);
    for (int i = 0; i < N; i++) {
        std::cin >> H[i];
    }

    std::vector<std::pair<int, int>> stk;
    i64 sum = 0;
    for (int i = 0; i < N; i++) {
        int cnt = 1;
        while (!stk.empty() && H[i] > H[stk.back().first]) {
            sum -= 1LL * H[stk.back().first] * stk.back().second;
            cnt += stk.back().second;
            stk.pop_back();
        }

        stk.push_back({i, cnt});
        sum += 1LL * H[i] * cnt;
        std::cout << sum + 1 << " \n"[i == N - 1];
    }


    return 0;
}
