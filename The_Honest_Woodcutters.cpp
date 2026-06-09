#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        A[i]--;
    }

    for (int i = 0; i < N; i++) {
        int B;
        std::cin >> B;
        B--;
        if (A[B] != i) {
            std::cout << "No\n";
            return;
        }
    }
    std::cout << "Yes\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
