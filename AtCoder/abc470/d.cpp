#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> A(N), invA(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        A[i]--;
        invA[A[i]] = i;
    }

    bool f = false;
    while (Q--) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int x, y;
            std::cin >> x >> y;
            x--, y--;
            if (!f) {
                std::swap(A[x], A[y]);
                invA[A[x]] = x;
                invA[A[y]] = y;
            } else {
                std::swap(invA[x], invA[y]);
                A[invA[x]] = x;
                A[invA[y]] = y;
            }
        } else {
            f = !f;
        }
    }

    if (!f) {
        for (auto x : A) {
            std::cout << x + 1 << " ";
        }
    } else {
        for (auto x : invA) {
            std::cout << x + 1 << " ";
        }
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
