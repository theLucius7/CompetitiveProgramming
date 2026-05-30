#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::set<i64> set{0LL};
    i64 sum = 0;
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;

        sum += (i & 1 ? 1 : -1) * a;
        set.insert(sum);
    }

    if (set.size() != n + 1) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }


    return 0;
}