#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> A(N);
    std::vector<int> vec;
    std::vector<bool> vis(N);
    int sum = 0;
    for (int i = 0; i < Q; i++) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int x;
            std::cin >> x;
            x--;
            sum ^= A[x];
            A[x]++;
            if (!vis[x]) {
                vis[x] = true;
                vec.push_back(x);
            }
            
            sum ^= A[x];
        } else {
            std::vector<int> nvec;
            std::vector<bool> nvis(N);
            for (int j = 0; j < vec.size(); j++) {
                sum ^= A[vec[j]];
                A[vec[j]]--;
                sum ^= A[vec[j]];
                if (A[vec[j]]) {
                    if (!nvis[vec[j]]) {
                        nvis[vec[j]] = true;
                        nvec.push_back(vec[j]);
                    }

                }
            }
            std::swap(vec, nvec);
            std::swap(vis, nvis);
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
