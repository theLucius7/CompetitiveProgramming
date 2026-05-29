#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k;
	std::cin >> n >> k;
	
	std::vector<int> x(k);
	for (int i = 0; i < k; i++) {
		std::cin >> x[i];
	}

	std::sort(x.begin(), x.end());
	int cur = 0;
	for (int i = k - 1; i >= 0; i--) {
		if (x[i] > cur) {
			cur += n - x[i];
		} else {
			std::cout << k - 1 - i << "\n";
			return;
		}
	}
	std::cout << k << "\n";
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