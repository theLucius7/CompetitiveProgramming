#include <bits/stdc++.h>
using i64 = long long;

struct M {
    i64 b, c;
};

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::multiset<i64> S;
    for (int i = 0; i < n; i++) {
        i64 a;
        std::cin >> a;
        S.insert(a);
    }

    std::vector<i64> B(m), C(m);
    for (int i = 0; i < m; i++) {
        std::cin >> B[i];
    }
    for (int i = 0; i < m; i++) {
        std::cin >> C[i];
    }

    std::vector<M> A, Z;
    for (int i = 0; i < m; i++) {
        if (C[i] > 0) {
            A.push_back({B[i], C[i]});
        }
        else {
            Z.push_back({B[i], 0});   
        }
    }

    i64 ans = 0;

    std::sort(A.begin(), A.end(), [&](const M &x, const M &y) {
        if (x.b != y.b) return x.b < y.b;
        return x.c > y.c;
    });


    for (auto &e : A) {
        auto it = S.lower_bound(e.b);
        if (it == S.end()) {
            break;
        }
        i64 x = *it;
        S.erase(it);
        ans++;
        S.insert(std::max(x, e.c));
    }

    std::sort(Z.begin(), Z.end(), [&](const M &x, const M &y) {
        if (x.b != y.b) return x.b < y.b;
        return x.c > y.c;
    });

    for (auto &e : Z) {
        auto it = S.lower_bound(e.b);
        if (it == S.end()) break;
        S.erase(it);
        ans++;
    }

    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}
