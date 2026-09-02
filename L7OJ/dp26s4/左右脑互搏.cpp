#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    int s = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        s ^= a[i];
    }

    std::vector<int> st(1 << n, -1);
    st[0] = false;
    auto dfs = [&](auto self, int x, int sum) -> bool{
        if (st[x] != -1) {
            return st[x] == 1 ? true : false;
        }

        for (int i = 0; i < n; i++) {
            if ((x >> i) & 1) {
                if (a[i] > (sum ^ a[i])) {
                    int nx = (x & ~(1 << i));
                    if(!self(self, nx, sum ^ a[i])) {
                        return st[x] = true;
                    }
                }
            }
        }

        return st[x] = false;
    };

    std::cout << (dfs(dfs, (1 << n) - 1, s) ? "Left" : "Right") << "\n";


}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
