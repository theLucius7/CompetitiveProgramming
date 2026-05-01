#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        if (a[i] < 0 || (i >= n - 2 && a[i] != 0)) {
            std::cout << "NO\n";
            return;
        }

        if (i + 2 < n) {
            a[i + 2] -= a[i];
            a[i + 1] -= 2 * a[i];
            a[i] = 0;
        }
    }
    std::cout << "YES\n";
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