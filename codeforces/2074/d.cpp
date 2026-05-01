#include <bits/stdc++.h>

using i64 = long long;

i64 sqrti64(i64 n) {
    i64 lo = 0, hi = 1E8;
    while (lo < hi) {
        i64 x = (lo + hi + 1) / 2;
        if (x * x <= n) {
            lo = x;
        } else {
            hi = x - 1;
        }
    }
    return lo;
}

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<int> x(n);
	for (int i = 0; i < n; i++) {
		std::cin >> x[i];
	}

	std::vector<int> r(n);
	for (int i = 0; i < n; i++) {
		std::cin >> r[i];
	}

	std::unordered_map<i64, i64> cnt;
	for (int i = 0; i < n; i++) {
		i64 a = x[i] - r[i], b = x[i] + r[i];
		for (i64 j = a; j <= b; j++) {
			cnt[j] = std::max(cnt[j], 2 * (i64)std::sqrt((i64)r[i] * r[i] - (x[i] - j) * (x[i] - j)) + 1);
		}
	}

	i64 ans = 0;
	for (auto [k, v] : cnt) {
		ans += v;
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