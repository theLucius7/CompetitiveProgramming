#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::map<std::pair<int, int>, int> ab, ac, bc;
    std::map<std::tuple<int, int, int>, int> abc;
    for (int i = 0; i + 2 < n; i++) {
        ab[{a[i], a[i + 1]}]++, ac[{a[i], a[i + 2]}]++, bc[{a[i + 1], a[i + 2]}]++;
        abc[{a[i], a[i + 1], a[i + 2]}]++;
    }

    i64 ans = 0;
    for (auto [k, v] : ab) {
        ans += (i64)v * (v - 1) / 2;
    }
    for (auto [k, v] : bc) {
        ans += (i64)v * (v - 1) / 2;
    }
    for (auto [k, v] : ac) {
        ans += (i64)v * (v - 1) / 2;
    }
    for (auto [k, v] : abc) {
        ans -= (i64)3 * v * (v - 1) / 2;
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