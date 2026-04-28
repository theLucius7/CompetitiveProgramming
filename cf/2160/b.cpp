#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    int n;
    std::cin >> n;

    std::vector<i64> b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    std::vector<int> p(n);
    int pre = 0;
    for (int i = 0; i < n; i++) {
        p[i] = i - b[i] + pre;
        pre = b[i];
    }

    std::vector<int> a(n);
    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (p[i] == -1) {
            a[i] = ++cur;
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i] != 0) {
            continue;
        }

        int u = i;
        std::vector<int> stk;
        while (a[u] == 0 && p[u] != -1) {
            stk.push_back(u);
            u = p[u];
        }
        if (a[u] == 0) {
            a[u] = ++cur;
        }
        int val = a[u];
        for (int v : stk) {
            a[v] = val;
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " \n"[i == n - 1];
    }
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
