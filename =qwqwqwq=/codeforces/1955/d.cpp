#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::unordered_map<int, int> need, have;

    std::vector<int> b(m);
    for (int i = 0; i < m; i++) {
        std::cin >> b[i];
        need[b[i]]++;
    }

    int cnt = 0, ans = 0;
    for (int i = 0; i < m; i++) {
        have[a[i]]++;
        if (have[a[i]] <= need[a[i]]) {
            cnt++;
        }
    }
    ans += (cnt >= k);

    for (int i = m; i < n; i++) {
        have[a[i - m]]--;
        if (have[a[i - m]] < need[a[i - m]]) {
            cnt--;
        }
        have[a[i]]++;
        if (have[a[i]] <= need[a[i]]) {
            cnt++;
        }
        ans += (cnt >= k);
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