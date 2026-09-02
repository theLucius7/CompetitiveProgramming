#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> A(N);
    int max = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        max = std::max(max, A[i]);
    }

    std::vector<int> cnt(max + 1, 0);
    for (int a : A) {
    	cnt[a]++;
    }

    std::vector<i64> pc(max + 1, 0), ps(max + 1, 0);
    for (int v = 1; v <= max; v++) {
        pc[v] = pc[v - 1] + cnt[v];
        ps[v] = ps[v - 1] + 1LL * v * cnt[v];
    }

    i64 S = std::accumulate(A.begin(), A.end(), 0LL);
    i64 M = max;

    while (Q--) {
        int B;
        std::cin >> B;

        if (M < B) { 
            std::cout << -1 << '\n';
            continue;
        }

        int t = std::min(B - 1, max);
		i64 x = ps[t];
		i64 cnt = N - pc[t];

        std::cout << std::min(S, x + 1LL * (B - 1) * cnt + 1) << '\n';
    }
    return 0;
}
