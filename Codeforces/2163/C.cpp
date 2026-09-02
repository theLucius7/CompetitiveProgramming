#include <bits/stdc++.h>

constexpr int inf = 1E9 + 1;

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    
    std::vector<int> premin(n), premax(n), sufmin(n), sufmax(n);
    premin[0] = a[0], premax[0] = a[0];
    for (int i = 1; i < n; i++) {
        premin[i] = std::min(premin[i - 1], a[i]);
        premax[i] = std::max(premax[i - 1], a[i]);
    }

    sufmin[n - 1] = b[n - 1], sufmax[n - 1] = b[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        sufmin[i] = std::min(sufmin[i + 1], b[i]);
        sufmax[i] = std::max(sufmax[i + 1], b[i]);
    }

    std::vector<std::pair<int,int>> v;
    for (int i = 0; i < n; i++) {
        v.emplace_back(std::max(premax[i], sufmax[i]), std::min(premin[i], sufmin[i]));
    }

    std::sort(v.begin(), v.end());

    i64 ans = 0;
    int max = 0, k = 0;
    for (int r = 1; r <= 2 * n; r++) {
        while (k < n && v[k].first <= r) {
            max = std::max(max, v[k].second);
            k++;
        }
        ans += max;
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
