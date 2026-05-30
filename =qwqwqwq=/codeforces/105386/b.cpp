#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	i64 k;
	std::cin >> n >> k;

	std::vector<i64> a(n);
	i64 ans = 0;
	std::vector<i64> v;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		ans += a[i] / k;
		a[i] %= k;
		a[i] = k - a[i];
		if (a[i]) {
			v.push_back(a[i]);
		}
	}

	std::sort(v.begin(), v.end());
	
	std::vector<i64> sum(n + 1);
	for (int i = 0; i < n; i++) {
		sum[i + 1] = sum[i] + v[i];
	}

	i64 m;
	std::cin >> m;

	auto it = std::upper_bound(sum.begin(), sum.end(), m);
	ans += (it - sum.begin() - 1);
	it--;
	m -= *it;

	std::cout << ans + m / k << "\n";
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