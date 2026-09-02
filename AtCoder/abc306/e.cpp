#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N, K, Q;
    std::cin >> N >> K >> Q;
    
    std::multiset<int> S, T;
    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        if (i < K) {
            S.insert(0);
        } else {
            T.insert(0);
        }
    }
    i64 ans = 0;
    
    while (Q--) {
        int X, Y;
        std::cin >> X >> Y;
        X--;
        if (S.contains(A[X])) {
            S.extract(A[X]);
            ans -= A[X];
        } else {
            T.extract(A[X]);
        }
        A[X] = Y;
        S.insert(A[X]);
        ans += A[X];
        while (S.size() > K) {
            int x = *S.begin();
            T.insert(S.extract(x));
            ans -= x;
        }
        while (!S.empty() && !T.empty() && *S.begin() < *T.rbegin()) {
            int x = *S.begin();
            int y = *T.rbegin();
            ans += y - x;
            T.insert(S.extract(x));
            S.insert(T.extract(y));
        }
        std::cout << ans << "\n";
    }
    
    return 0;
}
