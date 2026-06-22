#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int N;
    char A;
    std::cin >> N >> A;

    std::vector<std::string> s(N);
    for (int i = 0; i < N; i++) {
        std::cin >> s[i];
    }

    for (int i = 0; i < N; i++) {
        if (s[i][A - 'A'] == 'o') {
            std::cout << "Yes\n";
            return;
        }
    }
    std::cout << "No\n";
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
