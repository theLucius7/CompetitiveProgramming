#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<std::pair<int, int>>> day(M);
    std::vector<int> cnt(N);
    int sum = 0;
    for (int i = 0; i < N; i++) {
        int A, D, B;
        std::cin >> A >> D >> B;
        A--, D--, B--;

        day[D].push_back({A, B});
        
        cnt[A]++;
        if (cnt[A] == 1) {
            sum++;
        }
    }


    for (int i = 0; i < M; i++) {
        for(auto [A, B] : day[i]) {
            cnt[A]--;
            if (cnt[A] == 0) {
                sum--;
            }

            cnt[B]++;
            if (cnt[B] == 1) {
                sum++;
            }
        }
        std::cout << sum << "\n";
        
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
