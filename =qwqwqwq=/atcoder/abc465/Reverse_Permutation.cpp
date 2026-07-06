#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    int l = 0, r = N - 1;
    bool f = false;
    std::vector<int> a(N);

    for (int i = N - 1; i >= 0; i--) {
        if (S[i] == 'o') {
            f = !f;
        }

        if (f) {
            a[l] = i + 1;
            l++;
        } else {
            a[r] = i + 1;
            r--;
        }
    }

    for (int i = 0; i < a.size(); i++) {
        std::cout << a[i] << " \n"[i == a.size() - 1];
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
