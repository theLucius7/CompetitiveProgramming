#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::vector<int> h(n);
	for (int i = 0; i < n; i++) {
		std::cin >> h[i];
	}

	std::vector<int> a{h[k - 1]};
	for (int i = 0; i < n; i++) {
		if (i + 1 == k) {
			continue;
		}

		if (h[i] > h[k - 1]) {
			a.push_back(h[i]);
		}
	}

	std::sort(a.begin(), a.end());

	int max = 0;
	for (int i = 1; i < a.size(); i++) {
		max = std::max(max, a[i] - a[i - 1]);
	}
	std::cout << (max <= h[k - 1] ? "YES" : "NO") << "\n";
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