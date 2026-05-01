#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> b(n), c(m);
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }   
    for (int i = 0; i < m; i++) {
        std::cin >> c[i];
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (b[i] + c[j] <= k) {
                cnt++;
            }
        }
    }

    std::cout << cnt << "\n";
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