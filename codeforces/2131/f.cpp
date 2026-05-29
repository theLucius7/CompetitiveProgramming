#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::string a, b;
    std::cin >> a >> b;

    int sa = 0;
    std::vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        sa += (a[i] == '1');
        x[i] = 2 * sa - (i + 1);
    }

    int cb = 0;
    for (int i = 0; i < n; i++) {
        cb += (b[i] == '1');
        y[i] = 2 * cb - (i + 1);
    }

    std::sort(y.begin(), y.end());
    std::vector<i64> pref(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + y[i];
    }

    auto sum = [&](int u) -> i64 {
        int k = std::lower_bound(y.begin(), y.end(), u) - y.begin();
        i64 L = 1LL * u * k - pref[k], R = (pref[n] - pref[k]) - 1LL * u * (n - k);
        return L + R;
    };

    i64 res = 0;
    for (int i = 0; i < n; i++) {
        res += sum(-x[i]);
    }
    std::cout << (1LL * n * n * (n + 1) - res) / 2 << "\n";
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
