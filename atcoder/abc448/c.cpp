#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N, Q;
    std::cin >> N >> Q;

    std::vector<std::array<int, 2>> v(N);
    for (int i = 0; i < N; i++) {
        int A;
        std::cin >> A;
        v[i] = {A, i};
    }

    std::sort(v.begin(), v.end());

    while (Q--) {
        int K;
        std::cin >> K;

        std::vector<bool> vis(N);
        for (int i = 0; i < K; i++) {
            int B;
            std::cin >> B;
            B--;
            vis[B] = true;
        }

        for (int i = 0; i < N; i++) {
            if (!vis[v[i][1]]) {
                std::cout << v[i][0] << "\n";
                break;
            }
        }
    }

    return 0;
}
